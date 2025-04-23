#pragma once

#include "../team.hpp"

#include "../../unity/component/component.hpp"
#include "../../structures/vec3.hpp"

#include <string>

class c_photon_player;
class c_biped_map;
class c_aiming_data;

class c_player_controller : public c_component
{
public:
    ~c_player_controller( ) = default;
    c_player_controller( ) = default;

    c_photon_player* photon_player( ) const;
    team_t get_team( ) const;
    bool alive( ) const;
    int get_health( ) const;
    vec3_t get_position( ) const;
    std::string get_weapon_name( ) const;
    c_biped_map* biped_map( ) const;
    c_aiming_data* aiming_data( ) const;
    void fix_occlusion( ) const;
};