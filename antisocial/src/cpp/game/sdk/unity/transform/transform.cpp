#include "transform.hpp"

#include "../../il2cpp/il2cpp.hpp"

#include "globals.hpp"

vec3_t c_transform::get_position( ) const
{
    static auto func = reinterpret_cast< vec3_t ( * )( uintptr_t ) >( g_ctx->il2cpp->get_method_pointer( "UnityEngine", "Transform", "get_position", 0 ) );
    return func( reinterpret_cast< uintptr_t >( this ) );
}

vec3_t c_transform::get_forward( ) const
{
    static auto func = reinterpret_cast< vec3_t ( * )( uintptr_t ) >( g_ctx->il2cpp->get_method_pointer( "UnityEngine", "Transform", "get_forward", 0 ) );
    return func( reinterpret_cast< uintptr_t >( this ) );
}

vec3_t c_transform::get_up( ) const
{
    static auto func = reinterpret_cast< vec3_t ( * )( uintptr_t ) >( g_ctx->il2cpp->get_method_pointer( "UnityEngine", "Transform", "get_up", 0 ) );
    return func( reinterpret_cast< uintptr_t >( this ) );
}

void c_transform::set_position( vec3_t position ) const
{
    static auto func = reinterpret_cast< void ( * )( uintptr_t, vec3_t ) >( g_ctx->il2cpp->get_method_pointer( "UnityEngine", "Transform", "set_position", 1 ) );
    func( reinterpret_cast< uintptr_t >( this ), position );
}

void c_transform::set_local_euler( vec3_t rotation ) const
{
    static auto fn = reinterpret_cast< void ( * )( uintptr_t, vec3_t ) >( g_ctx->il2cpp->get_method_pointer( "UnityEngine", "Transform", "set_localEulerAngles", 1 ) );
    fn( reinterpret_cast< uintptr_t >( this ), rotation );
}
