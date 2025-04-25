#include "ragebot.hpp"

#include "game/sdk/axlebolt/player_controller/player_controller.hpp"
#include "game/sdk/axlebolt/biped_map/biped_map.hpp"
#include "game/sdk/axlebolt/aiming_data/aiming_data.hpp"
#include "game/sdk/axlebolt/photon_player/photon_player.hpp"
#include "game/sdk/unity/transform/transform.hpp"
#include "game/sdk/unity/camera/camera.hpp"
#include "game/sdk/unity/physics/physics.hpp"
#include "game/sdk/unity/unity.hpp"
#include "game/sdk/misc/math/math.hpp"

#include "game/features/visual/thirdperson/thirdperson.hpp"

#include "game/entities/entities.hpp"

#include "globals.hpp"

bool c_ragebot::autowall( const vec3_t& start, const vec3_t& end ) const
{
    if ( !c::get< bool >( g_ctx->cfg.ragebot_autowall ) )
        return false;

    vec3_t const direction = ( end - start ).normalized( );
    float const distance = vec3_t::distance( start, end );

    if ( distance > 40.f )
        return false;

    vec3_t current_point = start;
    vec3_t previous_hit_point = { };
    bool has_previous_hit = false;

    constexpr float step = 0.01f;
    // constexpr float max_penetration_loss = 100.0f;
    float total_penetration_loss = 0.0f;

    while ( true )
    {
        vec3_t next_point = current_point + direction * step;

        if ( vec3_t::distance( start, next_point ) > distance )
        {
            next_point = end;
        }

        raycast_hit_t hit;
        if ( c_physics::linecast( current_point, next_point, &hit, 16384 ) )
        {
            c_component* const collider = c_physics::raycast_get_collider( &hit );

            if ( collider )
            {
                unity::string* const surface_tag = collider->get_tag( );
                if ( surface_tag )
                {
                    std::string const surface_name = surface_tag->to_cpp_string( );
                    int const surface_type = c_physics::surface_from_tag( surface_tag );

                    if ( !math::check_surface_by_type( surface_type ) || surface_type == surface_mark_trigger )
                    {
                        return false;
                    }

                    float const thickness = has_previous_hit ? vec3_t::distance( previous_hit_point, hit.point ) : 0.01f;

                    float const penetration_loss = c_physics::get_penetration_loss( surface_type, thickness );

                    total_penetration_loss += penetration_loss;

                    if ( total_penetration_loss > 100 )
                    {
                        return false;
                    }

                    previous_hit_point = hit.point;
                    has_previous_hit = true;

                    current_point = hit.point + direction * step;
                }
            }
        } else
        {
            current_point = next_point;
        }

        if ( current_point == end )
        {
            break;
        }
    }

    return true;
}

c_transform* c_ragebot::select_bone( c_biped_map* biped_map, const vec3_t& view ) const
{
    std::vector< c_transform* > bones;

    biped_map->get_customized( bones,
                               c::get< bool >( g_ctx->cfg.ragebot_head ),
                               c::get< bool >( g_ctx->cfg.ragebot_body ),
                               c::get< bool >( g_ctx->cfg.ragebot_arms ),
                               c::get< bool >( g_ctx->cfg.ragebot_legs ) );

    for ( auto const& bone : bones )
    {
        if ( !bone )
            continue;

        bool const visible = !c_physics::linecast( view, bone->get_position( ), 16384 );

        bool const wallbang = [ & ]( ) -> bool {
            if ( !c::get< bool >( g_ctx->cfg.ragebot_autowall ) )
                return false;

            raycast_hit_t hit;
            if ( !c_physics::linecast( view, bone->get_position( ), &hit, 16384 ) )
                return false;

            c_component* const collider = c_physics::raycast_get_collider( &hit );

            if ( !collider )
                return false;

            unity::string* const surface_tag = collider->get_tag( );
            if ( !surface_tag )
                return false;

            std::string const surface_name = surface_tag->to_cpp_string( );
            int const surface_type = c_physics::surface_from_tag( surface_tag );

            if ( math::check_surface_by_type( surface_type ) && surface_type != surface_mark_trigger )
                return true;

            return false;
        }( );

        if ( visible || wallbang )
            return bone;
    }

    return bones[ 0 ];
}

void c_ragebot::execute( c_player_controller* local )
{
    if ( !c::get< bool >( g_ctx->cfg.ragebot_enabled ) )
        return;

    if ( !local || !local->alive( ) || c_players_database::get( )->m_players.empty( ) )
        return;

    auto* const target = c_players_database::get( )->get_ragebot_entity( );
    if ( !target || !target->alive( ) )
        return;

    auto* const photon = target->photon_player( );
    if ( !photon || photon->get_property< bool >( "untouchable" ) )
        return;

    vec3_t const view_position = g_ctx->features.thirdperson->get_unmodified_view( );

    auto* const bone = select_bone( target->biped_map( ), view_position );
    if ( !bone )
        return;

    vec3_t const position = bone->get_position( );

    bool const linecast = c_physics::linecast( view_position, position, 16384 );
    bool const wallbang = autowall( view_position, position );
    if ( linecast && !wallbang )
        return;

    if ( !c::get< bool >( g_ctx->cfg.ragebot_silent ) )
    {
        auto* const data = local->aiming_data( );
        if ( !data )
            return;

        vec3_t rotation = vec3_t::to_euler_rad( quater_t::look_rotation( position - view_position ) );

        if ( rotation.x >= 275.0f )
            rotation.x -= 360.0f;
        if ( rotation.x <= -275.0f )
            rotation.x += 360.0f;

        data->cur_aim_ang< vec3_t >( ) = rotation;
        data->cur_euler_ang< vec3_t >( ) = rotation;
    } else
    {
        m_target = bone;
        m_start = view_position;

        if ( c::get< bool >( g_ctx->cfg.ragebot_triggerbot ) )
            m_fire = true;
    }
}

void c_ragebot::cast_hit( vec3_t& start_position, vec3_t& target_position, uintptr_t parameters )
{
    if ( !m_target )
        return;

    if ( c::get< bool >( g_ctx->cfg.ragebot_silent ) )
    {
        start_position = m_start;
        target_position = ( m_target->get_position( ) - m_start ).normalized( );
    }

    m_target = nullptr;
}

void c_ragebot::antiaim( c_player_controller* local ) const
{
    if ( !local || !c::get< bool >( g_ctx->cfg.ragebot_antiaim ) )
        return;

    uintptr_t const aim_controller = *reinterpret_cast< uintptr_t* >( reinterpret_cast< uintptr_t >( local ) + 0x90 );
    if ( !aim_controller )
        return;

    uintptr_t const aiming_data = *reinterpret_cast< uintptr_t* >( aim_controller + 0x90 );
    if ( !aiming_data )
        return;

    uintptr_t const offset_on_crouch = *reinterpret_cast< uintptr_t* >( aiming_data + 0x38 );
    uintptr_t const offset_on_stand = *reinterpret_cast< uintptr_t* >( aiming_data + 0x30 );
    uintptr_t const offset_gun = *reinterpret_cast< uintptr_t* >( aiming_data + 0x40 );

    if ( !offset_gun || !offset_on_stand || !offset_on_crouch )
        return;

    *reinterpret_cast< vec3_t* >( offset_on_crouch + 0x1C ) = c::get< vec3_t >( g_ctx->cfg.antiaim_substitute );
    *reinterpret_cast< vec3_t* >( offset_on_stand + 0x1C ) = c::get< vec3_t >( g_ctx->cfg.antiaim_substitute );
    *reinterpret_cast< vec3_t* >( offset_gun + 0x1C ) = c::get< vec3_t >( g_ctx->cfg.antiaim_substitute );

    auto* const character = *reinterpret_cast< c_transform** >( aim_controller + 0xF0 );
    if ( !character )
        return;

    character->set_local_euler( c::get< vec3_t >( g_ctx->cfg.antiaim_rotation ) );
}