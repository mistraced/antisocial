#include "physics.hpp"

#include "game/sdk/il2cpp/il2cpp.hpp"

#include "globals.hpp"

bool c_physics::linecast( vec3_t start, vec3_t end, int mask )
{
    static auto fn = reinterpret_cast< bool ( * )( vec3_t, vec3_t, int ) >( g_ctx->il2cpp->get_method_pointer( "UnityEngine", "Physics", "Linecast", 3 ) );
    return fn( start, end, mask );
}