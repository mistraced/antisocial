#pragma once

#include "singleton.hpp"

class c_player_controller;

class c_bunnyhop : public singleton< c_bunnyhop >
{
public:
    void execute( c_player_controller* entity ) const;
};