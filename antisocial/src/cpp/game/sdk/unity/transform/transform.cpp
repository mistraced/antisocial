#include "transform.hpp"

#include "../../il2cpp/il2cpp.hpp"

#include "globals.hpp"

vec3_t c_transform::get_position( ) const
{
    static auto func = reinterpret_cast< vec3_t ( * )( uintptr_t ) >( g_ctx->il2cpp->get_method_pointer( "UnityEngine", "Transform", "get_position", 0 ) );
    return func( reinterpret_cast< uintptr_t >( this ) );
}