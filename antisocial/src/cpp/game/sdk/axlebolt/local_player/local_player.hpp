#pragma once

#include "../team.hpp"

#include "../player_controller/player_controller.hpp"

class c_local_player : public c_player_controller
{
public:
    static team_t m_team;
};