#include "thirdperson.hpp"

#include "game/sdk/axlebolt/player_controller/player_controller.hpp"
#include "game/sdk/unity/transform/transform.hpp"
#include "game/sdk/unity/camera/camera.hpp"
#include "game/sdk/unity/component/component.hpp"

#include "game/entities/entities.hpp"

#include "globals.hpp"

void c_thirdperson::late( c_player_controller* local ) const
{
    if ( !local || !local->alive( ) || !c::get< bool >( g_ctx->cfg.misc_thirdperson ) )
        return;

    auto* const main_camera = c_camera::get_main( );
    if ( !main_camera )
        return;

    auto* const transform = reinterpret_cast< c_component* >( main_camera )->get_transform( );
    if ( !transform )
        return;

    vec3_t const position = transform->get_position( );
    vec3_t const forward = transform->get_forward( );
    vec3_t const up = transform->get_up( );
    vec3_t const entity_location = local->get_position( );

    vec3_t const camera_position = entity_location + vec3_t( 0, 1.65f, 0 ) - ( forward * 3 );

    // flexhack type shit
    vec3_t const adjusted = camera_position + ( ( ( up * 3 ) / 2.0f ) / 5.0f );

    transform->set_position( adjusted );
}

void c_thirdperson::update( c_player_controller* entity ) const
{
    if ( !entity || !entity->alive( ) )
        return;

    if ( c::get< bool >( g_ctx->cfg.misc_thirdperson ) )
        entity->set_tps_view( );
    else
        entity->set_fps_view( );
}

vec3_t c_thirdperson::get_unmodified_view( ) const
{
    auto* const main_camera = c_camera::get_main( );
    if ( !main_camera )
        return { 0, 0, 0 };

    auto* const transform = reinterpret_cast< c_component* >( main_camera )->get_transform( );
    if ( !transform )
        return { 0, 0, 0 };

    auto* const local = c_players_database::get( )->m_local_player;
    if ( !local || !local->alive( ) )
        return { 0, 0, 0 };

    vec3_t const position = transform->get_position( );
    vec3_t const entity_location = local->get_position( );

    vec3_t const camera_position = entity_location + vec3_t( 0, 1.65f, 0 );

    return c::get< bool >( g_ctx->cfg.misc_thirdperson ) ? camera_position : position;
}