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

    const char* watermark = "github.com/mistraced/antisocial";
    ImGui::GetBackgroundDrawList( )->AddText( { 41, 21 }, ImColor( 0, 0, 0, 120 ), watermark );
    ImGui::GetBackgroundDrawList( )->AddText( { 40, 20 }, ImColor( 255, 255, 255 ), watermark );

    if ( g_ctx->is_presented )
        forms::main.render( );

    for ( auto const& func : m_queue )
    {
        func( );
    }
}