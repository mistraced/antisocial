#include "occlusion_controller.hpp"

#include "../../il2cpp/il2cpp.hpp"

#include "globals.hpp"

bool c_occlusion_controller::set_in_area( bool v ) const
{
    return *reinterpret_cast< bool* >( reinterpret_cast< uintptr_t >( this ) + 0x29 ) = v;
}

bool c_occlusion_controller::set_enabled( bool v ) const
{
    return *reinterpret_cast< bool* >( reinterpret_cast< uintptr_t >( this ) + 0x28 ) = v;
}

void c_occlusion_controller::set_visible( bool v ) const
{
    static auto fn = reinterpret_cast< void ( * )( uintptr_t, bool ) >( g_ctx->il2cpp->get_method_pointer( "Axlebolt.Standoff.Occlusion.Dynamic", "ObjectOccludee", "SetVisible", 1 ) );
    fn( reinterpret_cast< uintptr_t >( this ), v );
};