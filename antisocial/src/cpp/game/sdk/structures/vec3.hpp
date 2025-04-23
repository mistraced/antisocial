#pragma once

struct vec3_t
{
    union
    {
        struct
        {
            float x, y, z;
        };
        float data[ 3 ];
    };

    inline vec3_t( )
        : x( 0 )
        , y( 0 )
        , z( 0 ) {};

    inline vec3_t( float x, float y, float z )
        : x( x )
        , y( y )
        , z( z ) {};
};