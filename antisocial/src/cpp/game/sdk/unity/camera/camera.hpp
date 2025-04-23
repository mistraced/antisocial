#pragma once

#include "../../structures/vec3.hpp"

class c_camera
{
public:
    static c_camera* get_main( );

    vec3_t world_to_viewport( vec3_t position, int eye ) const;
};