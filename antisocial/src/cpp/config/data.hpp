#pragma once

#include "data_management.hpp"

#include "game/sdk/structures/vec3.hpp"

struct cfg_t
{
    declare_variable( bool, esp_rect, false );
    declare_variable( bool, esp_health, false );
    declare_variable( bool, esp_ammo, false );
    declare_variable( bool, esp_weapon, false );
    declare_variable( bool, esp_nickname, false );
    declare_variable( bool, esp_money, false );

    declare_variable( bool, ragebot_enabled, false );
    declare_variable( bool, ragebot_silent, false );
    declare_variable( bool, ragebot_triggerbot, false );
    declare_variable( bool, ragebot_antiaim, false );
    declare_variable( vec3_t, antiaim_substitute, vec3_t( 0, 0, 0 ) );
    declare_variable( vec3_t, antiaim_rotation, vec3_t( 0, 0, 0 ) );
    declare_variable( bool, ragebot_head, true );
    declare_variable( bool, ragebot_body, false );
    declare_variable( bool, ragebot_arms, false );
    declare_variable( bool, ragebot_legs, false );
    declare_variable( bool, ragebot_autowall, false );
    declare_variable( bool, ragebot_doubletap, false );
    declare_variable( int, ragebot_minimal_damage, 0 );

    declare_variable( bool, misc_thirdperson, false );
    declare_variable( bool, misc_peek_assist, false );

    declare_variable( bool, movement_bunnyhop, false );
};