#include "thirdperson.hpp"

#include "game/sdk/axlebolt/player_controller/player_controller.hpp"
#include "game/sdk/unity/transform/transform.hpp"
#include "game/sdk/unity/camera/camera.hpp"
#include "game/sdk/unity/component/component.hpp"
#include "game/sdk/unity/physics/physics.hpp"
#include "game/sdk/unity/unity.hpp"

#include "game/entities/entities.hpp"

#include "globals.hpp"

void c_thirdperson::late( c_player_controller* local ) const
{
    if ( !local /*|| !local->alive( )*/ || !c::get< bool >( g_ctx->cfg.misc_thirdperson ) )
        return;

    auto* const transform = local->main_camera_holder( );
    if ( !transform )
        return;

    vec3_t const forward = transform->get_forward( );
    vec3_t const up = transform->get_up( );
    vec3_t const entity_location = local->get_position( );

    vec3_t const camera_position = entity_location + vec3_t( 0, 1.65f, 0 ) - ( forward * 3 );

    // flexhack type shit
    vec3_t const adjusted = camera_position + ( ( ( up * 3 ) / 2.0f ) / 5.0f );

    raycast_hit_t hit;
    if ( c_physics::linecast( entity_location + vec3_t( 0.f, 1.6f, 0.f ), adjusted, &hit, 16384 ) )
    {
        c_component* const collider = c_physics::raycast_get_collider( &hit );

        if ( collider )
        {
            unity::string* const surface_tag = collider->get_tag( );
            if ( surface_tag )
            {
                std::string const surface_name = surface_tag->to_cpp_string( );
                int const surface_type = c_physics::surface_from_tag( surface_tag );

                if ( surface_type != surface_type::character && surface_type != surface_type::unknown && surface_type != surface_type::water && surface_type != surface_type::ground )
                {
                    transform->set_position( hit.point );

                    return;
                }
            }
        }
    }

    transform->set_position( adjusted );
}

void c_thirdperson::update( c_player_controller* entity ) const
{
    if ( !entity || !entity->alive( ) )
        return;

    static bool tps = false;

    auto const set_view_mode = [ & ]( bool enable_tps ) {
        if ( !enable_tps )
        {
            if ( tps )
            {
                entity->set_fps_view( );

                tps = false;
            }

            return;
        }

        entity->set_tps_view( );

        tps = true;
    };

    set_view_mode( c::get< bool >( g_ctx->cfg.misc_thirdperson ) );
}

vec3_t c_thirdperson::get_unmodified_view( ) const
{
    auto* const local = c_players_database::get( )->m_local_player;
    if ( !local || !local->alive( ) )
        return { 0, 0, 0 };

    auto* const transform = local->main_camera_holder( );
    if ( !transform )
        return { 0, 0, 0 };

    vec3_t const camera_position = transform->get_position( );

    vec3_t const entity_location = local->get_position( );
    vec3_t const adjusted_position = entity_location + vec3_t( 0, 1.65f, 0 );

    return c::get< bool >( g_ctx->cfg.misc_thirdperson ) ? adjusted_position : camera_position;
}