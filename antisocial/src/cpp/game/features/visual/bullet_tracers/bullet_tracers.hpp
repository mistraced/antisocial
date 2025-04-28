#pragma once

#include <vector>

#include "singleton.hpp"

#include "game/sdk/structures/vec3.hpp"
#include "animator/animator.hpp"

struct bullet_tracer_t
{
    vec3_t start, end;
    int alpha_modulate { 360 };
};

class c_bullet_tracers : public singleton< c_bullet_tracers >
{
    std::vector< bullet_tracer_t > m_tracers;

public:
    ~c_bullet_tracers( ) = default;
    c_bullet_tracers( ) = default;

    void push_tracer( const bullet_tracer_t& tracer );
    void render( );
    void clear( );
};