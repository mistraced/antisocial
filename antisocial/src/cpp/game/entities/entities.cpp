#include "entities.hpp"

#include "game/sdk/axlebolt/player_manager/player_manager.hpp"
#include "game/sdk/axlebolt/player_controller/player_controller.hpp"
#include "game/sdk/axlebolt/biped_map/biped_map.hpp"
#include "game/sdk/unity/physics/physics.hpp"
#include "game/sdk/unity/transform/transform.hpp"
#include "game/sdk/unity/camera/camera.hpp"

#include "game/features/features.hpp"

#include "game/features/visual/thirdperson/thirdperson.hpp"
#include "game/features/visual/esp/esp.hpp"

#include "game/features/ragebot/ragebot.hpp"

#include "globals.hpp"

void c_players_database::update( )
{
    auto const clear_data = [ & ]( ) -> void {
        m_players.clear( );
        m_local_player = nullptr;
        g_ctx->features.ragebot->m_target = nullptr;
    };

    auto* const player_manager = c_player_manager::get_instance( );
    if ( !player_manager )
    {
        clear_data( );
        return;
    }

    m_local_player = player_manager->get_local_player( );
    if ( !m_local_player || !m_local_player->alive( ) )
    {
        clear_data( );
        return;
    }

    m_players = player_manager->get_players( );

    c_local_player::m_team = m_local_player->get_team( );

    // let's also process them there for now
    for ( auto* const entity : m_players )
    {
        if ( !entity || !entity->alive( ) )
            continue;

        entity->fix_occlusion( );

        g_ctx->features.esp->process_ent_player( entity );
    }

    g_ctx->features_mgr->process_local_player( m_local_player );
}

c_player_controller* c_players_database::get_ragebot_entity( ) const
{
    vec3_t const view_position = g_ctx->features.thirdperson->get_unmodified_view( );

    for ( auto* const entity : m_players )
    {
        if ( !entity || !entity->alive( ) )
            continue;

        c_biped_map* const biped_map = entity->biped_map( );
        if ( !biped_map )
            continue;

        auto* const head = biped_map->head( );
        if ( !head )
            continue;

        if ( c_physics::linecast( view_position, head->get_position( ), 16384 ) )
            continue;

        return entity;
    }

    return nullptr;
}