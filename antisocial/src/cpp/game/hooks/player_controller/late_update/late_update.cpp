#include "late_update.hpp"

#include "game/sdk/axlebolt/player_controller/player_controller.hpp"

#include "game/features/visual/thirdperson/thirdperson.hpp"
#include "game/features/ragebot/ragebot.hpp"

#include "globals.hpp"

#include "game/entities/entities.hpp"

#include "memory_manager/memory_manager.hpp"

void hk::player_controller::late_update::hook( )
{
    memory_manager::hook( 0x1565424, reinterpret_cast< void* >( hk_update ), reinterpret_cast< void** >( &og_update ) );
}

void hk::player_controller::late_update::hk_update( c_player_controller* entity )
{
    og_update( entity );

    if ( !entity || !entity->alive( ) )
        return;

    auto* const local = c_players_database::get( )->m_local_player;
    if ( !local || !local->alive( ) )
        return;

    g_ctx->features.ragebot->antiaim( local );
    g_ctx->features.thirdperson->late( local );
}