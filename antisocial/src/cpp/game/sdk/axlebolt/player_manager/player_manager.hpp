#pragma once

#include <vector>

class c_player_controller;
class c_local_player;

class c_player_manager
{
    static uintptr_t m_networking_peer;
    static uintptr_t m_lazy_api;
    static uintptr_t m_game_api;

public:
    static c_player_manager* get_instance( );

    c_local_player* get_local_player( ) const;
    std::vector< c_player_controller* > get_players( ) const;
};