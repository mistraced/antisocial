#pragma once

#include "game/sdk/structures/vec3.hpp"

namespace hk::hit_caster::cast_hit
{
    inline uintptr_t ( *og_cast )( vec3_t, vec3_t, uintptr_t );
    extern uintptr_t hk_cast( vec3_t, vec3_t, uintptr_t );

    extern void hook( );
} // namespace hk::hit_caster::cast_hit