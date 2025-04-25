#include "component.hpp"
#include "../transform/transform.hpp"

#include "../../il2cpp/il2cpp.hpp"
#include "globals.hpp"

#include "../../unity/unity.hpp"

c_transform* c_component::get_transform( ) const
{
    static auto func = reinterpret_cast< c_transform* ( * ) ( uintptr_t ) >( g_ctx->il2cpp->get_method_pointer( "UnityEngine", "Component", "get_transform", 0 ) );
    return func( reinterpret_cast< uintptr_t >( this ) );
}

unity::string* c_component::get_tag( ) const
{
    static auto fn = reinterpret_cast< unity::string* ( * ) ( uintptr_t ) >( g_ctx->il2cpp->get_method_pointer( "UnityEngine", "Component", "get_tag", 0 ) );
    return fn( reinterpret_cast< uintptr_t >( this ) );
}