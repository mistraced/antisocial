#include "cast_hit.hpp"

#include "globals.hpp"

#include "game/features/ragebot/ragebot.hpp"

#include "memory_manager/memory_manager.hpp"

void hk::hit_caster::cast_hit::hook( )
{
    memory_manager::hook( 0x178F1DC, reinterpret_cast< void* >( hk_cast ), reinterpret_cast< void** >( &og_cast ) );
}

void hk::hit_caster::cast_hit::hk_cast( vec3_t start, vec3_t target, uintptr_t param )
{
    g_ctx->features.ragebot->cast_hit( start, target, param );

    return og_cast( start, target, param );
}