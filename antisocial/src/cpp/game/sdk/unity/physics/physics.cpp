#include "physics.hpp"

#include "game/sdk/il2cpp/il2cpp.hpp"

#include "globals.hpp"

#include "memory_manager/memory_manager.hpp"

#include "game/sdk/unity/component/component.hpp"
#include "game/sdk/unity/unity.hpp"

bool c_physics::linecast( vec3_t start, vec3_t end, int mask )
{
    static auto fn = reinterpret_cast< bool ( * )( vec3_t, vec3_t, int ) >( g_ctx->il2cpp->get_method_pointer( "UnityEngine", "Physics", "Linecast", 3 ) );
    return fn( start, end, mask );
}

bool c_physics::linecast( vec3_t start, vec3_t end, raycast_hit_t* ray, int mask )
{
    // il2cpp couldn't resolve this properly
    static auto fn = reinterpret_cast< bool ( * )( vec3_t, vec3_t, raycast_hit_t*, int ) >( memory_manager::get_absolute( 0x3AF5EE0 ) );
    return fn( start, end, ray, mask );
}

float c_physics::get_penetration_loss( int type, float thickness )
{
    static auto fn = reinterpret_cast< float ( * )( int, float ) >( memory_manager::get_absolute( 0x1795714 ) );
    return fn( type, thickness );
}

c_component* c_physics::raycast_get_collider( raycast_hit_t* ray )
{
    static auto fn = reinterpret_cast< c_component* ( * ) ( raycast_hit_t* ) >( g_ctx->il2cpp->get_method_pointer( "UnityEngine", "RaycastHit", "get_collider", 0 ) );
    return fn( ray );
}

surface_type c_physics::surface_from_tag( unity::string* tag )
{
    static auto fn = reinterpret_cast< surface_type ( * )( unity::string* ) >( g_ctx->il2cpp->get_method_pointer( "Axlebolt.Standoff.Inventory.Hit", "SurfaceTypeUtility", "POPPOPOPPPPOOPOOPOPPPOPPOPPOPOPOPPOOPPOOPPPOPOO", 1 ) );
    return fn( tag );
}
