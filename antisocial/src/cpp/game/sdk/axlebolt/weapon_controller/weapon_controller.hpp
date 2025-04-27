#pragma once

#include <cstdint>
#include <string>

class c_gun_controller;

class c_weapon_controller
{
public:
    bool is_gun( int id ) const;
    int get_id( ) const;
    c_gun_controller* get_gun( );
    uintptr_t get_commands( ) const;
    std::string get_name( ) const;
};