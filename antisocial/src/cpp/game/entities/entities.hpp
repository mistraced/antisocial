#pragma once

#include <cstdint>
#include <vector>

#include "singleton.hpp"

#include "game/sdk/axlebolt/local_player/local_player.hpp"

class c_player_controller;
class c_local_player;

class c_players_database : public singleton< c_players_database >
{
public:
    ~c_players_database( ) = default;
    c_players_database( ) = default;

    c_local_player* m_local_player;
    std::vector< c_player_controller* > m_players;

    void update( );
};