#include "interface.hpp"

#include "globals.hpp"

void c_interface::init( )
{
    forms::main.init( );
}

void c_interface::render( )
{
    if ( g_ctx->is_presented )
        forms::main.render( );

    for ( const auto& func : m_queue )
    {
        func( );
    }
}