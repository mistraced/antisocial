#include "ragebot.hpp"

#include "game/sdk/axlebolt/player_controller/player_controller.hpp"
#include "game/sdk/axlebolt/biped_map/biped_map.hpp"
#include "game/sdk/axlebolt/aiming_data/aiming_data.hpp"
#include "game/sdk/axlebolt/photon_player/photon_player.hpp"
#include "game/sdk/unity/transform/transform.hpp"
#include "game/sdk/unity/camera/camera.hpp"
#include "game/sdk/unity/physics/physics.hpp"

#include "game/features/visual/thirdperson/thirdperson.hpp"

#include "game/entities/entities.hpp"

#include "globals.hpp"

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

    auto* const head = target->biped_map( )->head( );
    if ( !head )
        return;

    vec3_t const position = head->get_position( );
    vec3_t const view_position = g_ctx->features.thirdperson->get_unmodified_view( );

    bool const linecast = c_physics::linecast( view_position, position, 16384 );
    if ( linecast )
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
        m_target = head;
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
    if ( !local || !local->alive( ) || !c::get< bool >( g_ctx->cfg.ragebot_antiaim ) )
        return;

    uintptr_t const aim_controller = *reinterpret_cast< uintptr_t* >( reinterpret_cast< uintptr_t >( local ) + 0x90 );
    if ( !aim_controller )
        return;

    uintptr_t const aiming_data = reinterpret_cast< uintptr_t >( aim_controller + 0x90 );
    if ( !aiming_data )
        return;

    uintptr_t const offset_on_crouch = *reinterpret_cast< uintptr_t* >( aiming_data + 0x38 );
    uintptr_t const offset_on_stand = *reinterpret_cast< uintptr_t* >( aiming_data + 0x30 );
    uintptr_t const offset_gun = *reinterpret_cast< uintptr_t* >( aiming_data + 0x40 );

    *reinterpret_cast< vec3_t* >( offset_on_crouch + 0x1C ) = c::get< vec3_t >( g_ctx->cfg.antiaim_substitute );
    *reinterpret_cast< vec3_t* >( offset_on_stand + 0x1C ) = c::get< vec3_t >( g_ctx->cfg.antiaim_substitute );
    *reinterpret_cast< vec3_t* >( offset_gun + 0x1C ) = c::get< vec3_t >( g_ctx->cfg.antiaim_substitute );

    c_transform* character = *reinterpret_cast< c_transform** >( aim_controller + 0xF0 );
    if ( !character )
        return;

    character->set_local_euler( c::get< vec3_t >( g_ctx->cfg.antiaim_rotation ) );
}