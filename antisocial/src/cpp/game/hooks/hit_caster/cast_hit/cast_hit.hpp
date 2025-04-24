#pragma once

#include "game/sdk/structures/vec3.hpp"

namespace hk::hit_caster::cast_hit
{
    inline void ( *og_cast )( vec3_t, vec3_t, uintptr_t );
    extern void hk_cast( vec3_t, vec3_t, uintptr_t );

    extern void hook( );
} // namespace hk::hit_caster::cast_hit