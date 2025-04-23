#include "interface.hpp"

#include "globals.hpp"

#include "imgui.h"
#include "imgui_internal.h"

void c_interface::init( )
{
    forms::main.init( );

    if ( m_initializer )
        m_initializer( );
}

void c_interface::render( )
{
    ImGui::GetBackgroundDrawList( )->Flags &= ~( ImDrawListFlags_AntiAliasedFill | ImDrawListFlags_AntiAliasedLines );

    if ( g_ctx->is_presented )
        forms::main.render( );

    for ( auto const& func : m_queue )
    {
        func( );
    }
}