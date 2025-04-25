#pragma once

#include "singleton.hpp"

#include "game/sdk/structures/vec3.hpp"

class c_player_controller;
class c_transform;
class c_biped_map;

class c_ragebot : public singleton< c_ragebot >
{
public:
    c_transform* m_target;
    vec3_t m_start;
    bool m_fire;

public:
    c_ragebot( ) = default;
    ~c_ragebot( ) = default;

    void execute( c_player_controller* local );
    c_transform* select_bone( c_biped_map* biped_map, const vec3_t& view ) const;
    bool autowall( const vec3_t& start, const vec3_t& end ) const;

    void cast_hit( vec3_t& start_position, vec3_t& target_position, uintptr_t parameters );

    void antiaim( c_player_controller* local ) const;
};