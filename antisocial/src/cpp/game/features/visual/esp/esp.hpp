#pragma once

#include <singleton.hpp>

class c_player_controller;

class c_esp : public singleton< c_esp >
{
public:
    ~c_esp( ) = default;
    c_esp( ) = default;

    void process_ent_player( c_player_controller* entity ) const;
};