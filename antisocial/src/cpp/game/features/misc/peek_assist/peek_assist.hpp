#pragma once

#include "singleton.hpp"

#include "game/sdk/structures/vec3.hpp"

class c_player_controller;

class c_peek_assist : public singleton< c_peek_assist >
{
public:
    bool m_peeking = true;
    bool m_peeked;
    vec3_t m_last_pos;

public:
    ~c_peek_assist( ) = default;
    c_peek_assist( ) = default;

    void execute( c_player_controller* local );
};