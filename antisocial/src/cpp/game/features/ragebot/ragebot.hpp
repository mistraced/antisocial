#pragma once

#include "singleton.hpp"

class c_player_controller;

class c_ragebot : public singleton< c_ragebot >
{
public:
    c_ragebot( ) = default;
    ~c_ragebot( ) = default;

    void execute( c_player_controller* local ) const;
};