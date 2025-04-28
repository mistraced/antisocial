#pragma once

#include <cmath>

class animation
{
public:
    ~animation( ) = default;
    animation( ) = default;

    animation( float i = 0.f )
        : value( i )
    {
    }

    void update( float to_value, float duration = 0.10f );

    float value = 0.f;
};