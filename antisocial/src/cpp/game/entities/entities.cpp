#include "entities.hpp"

#include "game/sdk/axlebolt/player_manager/player_manager.hpp"
#include "game/sdk/axlebolt/player_controller/player_controller.hpp"

#include "game/features/visual/esp/esp.hpp"

#include "globals.hpp"

void c_players_database::update( )
{
    auto* const player_manager = c_player_manager::get_instance( );
    if ( !player_manager || !player_manager->get_local_player( ) )
        return;

    m_players = player_manager->get_players( );

    m_local_player = player_manager->get_local_player( );
    if ( !m_local_player || !m_local_player->alive( ) )
        return;

    c_local_player::m_team = m_local_player->get_team( );

    // let's also process them there for now
    for ( auto* const entity : m_players )
    {
        if ( !entity || !entity->alive( ) )
            continue;

        g_ctx->features.esp->process_ent_player( entity );
    }
}