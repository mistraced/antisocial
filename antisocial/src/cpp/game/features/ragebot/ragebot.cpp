#include "ragebot.hpp"

#include "game/sdk/axlebolt/player_controller/player_controller.hpp"
#include "game/sdk/axlebolt/biped_map/biped_map.hpp"
#include "game/sdk/axlebolt/aiming_data/aiming_data.hpp"
#include "game/sdk/unity/transform/transform.hpp"
#include "game/sdk/unity/camera/camera.hpp"
#include "game/sdk/unity/physics/physics.hpp"

#include "game/entities/entities.hpp"

#include "globals.hpp"

void c_ragebot::execute( c_player_controller* local ) const
{
    if ( !g_ctx->cfg.ragebot_test )
        return;

    if ( !local || !local->alive( ) )
        return;

    auto* const target = c_players_database::get( )->get_ragebot_entity( );
    if ( !target || !target->alive( ) )
        return;

    auto* const head = target->biped_map( )->head( );
    if ( !head )
        return;

    vec3_t const position = head->get_position( );
    vec3_t const view_position = c_camera::get_view( );

    bool const linecast = c_physics::linecast( position, view_position, 16384 );
    if ( linecast )
        return;

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
}