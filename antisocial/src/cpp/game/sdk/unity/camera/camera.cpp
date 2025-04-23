#include "camera.hpp"

#include "game/sdk/il2cpp/il2cpp.hpp"

#include "globals.hpp"

#include "game/sdk/unity/component/component.hpp"
#include "game/sdk/unity/transform/transform.hpp"

c_camera* c_camera::get_main( )
{
    static auto func = reinterpret_cast< c_camera* ( * ) ( ) >( g_ctx->il2cpp->get_method_pointer( "UnityEngine", "Camera", "get_main", 0 ) );
    return func( );
}

vec3_t c_camera::get_view( )
{
    auto* const main = get_main( );
    if ( !main )
        return { 0, 0, 0 };

    auto* const transform = reinterpret_cast< c_component* >( main )->get_transform( );
    if ( !transform )
        return { 0, 0, 0 };

    return transform->get_position( );
}

vec3_t c_camera::world_to_viewport( vec3_t position, int eye ) const
{
    static auto func = reinterpret_cast< vec3_t ( * )( uintptr_t, vec3_t, int ) >( g_ctx->il2cpp->get_method_pointer( "UnityEngine", "Camera", "WorldToViewportPoint", 2 ) );
    return func( reinterpret_cast< uintptr_t >( this ), position, eye );
}