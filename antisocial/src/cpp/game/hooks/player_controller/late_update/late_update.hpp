#pragma once

class c_player_controller;

namespace hk::player_controller::late_update
{
    inline void ( *og_update )( c_player_controller* );
    extern void hk_update( c_player_controller* );

    extern void hook( );
} // namespace hk::player_controller::late_update