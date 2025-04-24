#pragma once

#include "singleton.hpp"

#include "game/sdk/structures/vec3.hpp"

class c_player_controller;

class c_thirdperson : public singleton< c_thirdperson >
{
public:
    ~c_thirdperson( ) = default;
    c_thirdperson( ) = default;

    void late( c_player_controller* entity ) const;
    void update( c_player_controller* entity ) const;

    vec3_t get_unmodified_view( ) const;
};