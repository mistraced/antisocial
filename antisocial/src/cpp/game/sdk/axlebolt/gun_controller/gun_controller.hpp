#pragma once

enum class gun_damage_t
{
    head,
    body,
    arms,
    legs
};

class c_gun_controller
{
public:
    float& time_fired( );
    int get_damage( gun_damage_t type ) const;
};