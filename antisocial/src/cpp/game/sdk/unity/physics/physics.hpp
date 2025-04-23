#pragma once

#include "../../structures/vec3.hpp"

class c_physics
{
public:
    static bool linecast( vec3_t start, vec3_t end, int mask );
};