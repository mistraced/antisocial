#include "get_inputs.hpp"

#include "game/features/ragebot/ragebot.hpp"

#include "game/sdk/axlebolt/player_inputs/player_inputs.hpp"

#include "globals.hpp"

#include "memory_manager/memory_manager.hpp"

void hk::player_inputs::get_inputs::hook( )
{
    memory_manager::hook( 0x193B95C, reinterpret_cast< void* >( hk_get ), reinterpret_cast< void** >( &og_get ) );
}

c_player_inputs* hk::player_inputs::get_inputs::hk_get( uintptr_t instance )
{
    c_player_inputs* ret = og_get( instance );

    if ( ret )
    {
        if ( g_ctx->features.ragebot->m_fire )
        {
            ret->fire( ) = true;
            g_ctx->features.ragebot->m_fire = false;
        }
    }

    return ret;
}