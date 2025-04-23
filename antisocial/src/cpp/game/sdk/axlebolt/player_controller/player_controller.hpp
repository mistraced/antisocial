#pragma once

#include "../team.hpp"

#include "../../unity/component/component.hpp"
#include "../../structures/vec3.hpp"

class c_photon_player;

class c_player_controller : public c_component
{
public:
    ~c_player_controller( ) = default;
    c_player_controller( ) = default;

    c_photon_player* photon_player( ) const;
    team_t get_team( ) const;
    bool alive( ) const;
    vec3_t get_position( ) const;
};