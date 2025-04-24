#pragma once

#include <cstdint>

class c_player_inputs;

namespace hk::player_inputs::get_inputs
{
    inline c_player_inputs* ( *og_get )( uintptr_t );
    extern c_player_inputs* hk_get( uintptr_t );

    extern void hook( );
} // namespace hk::player_inputs::get_inputs