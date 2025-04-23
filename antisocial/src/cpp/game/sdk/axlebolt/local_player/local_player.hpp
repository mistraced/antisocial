#pragma once

#include "../team.hpp"

#include "../player_controller/player_controller.hpp"

class c_local_player : public c_player_controller
{
public:
    ~c_local_player( ) = default;
    c_local_player( ) = default;

    static team_t m_team;
};