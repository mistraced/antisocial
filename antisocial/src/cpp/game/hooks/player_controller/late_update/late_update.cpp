#include "late_update.hpp"

#include "game/sdk/axlebolt/player_controller/player_controller.hpp"

#include "game/features/visual/thirdperson/thirdperson.hpp"
#include "game/features/ragebot/ragebot.hpp"

#include "game/sdk/axlebolt/aiming_data/aiming_data.hpp"

#include "globals.hpp"

#include "game/entities/entities.hpp"

#include "memory_manager/memory_manager.hpp"

void hk::player_controller::late_update::hook( )
{
    memory_manager::hook( 0x1565424, reinterpret_cast< void* >( hk_update ), reinterpret_cast< void** >( &og_update ) );
}

void hk::player_controller::late_update::hk_update( c_player_controller* entity )
{
    // yeah I fucking don't believe in anything anymore...
    if ( entity && c_players_database::get( )->m_local_player )
    {
        g_ctx->features.thirdperson->late( c_players_database::get( )->m_local_player );
        g_ctx->features.ragebot->antiaim( c_players_database::get( )->m_local_player );
    }

    og_update( entity );
}