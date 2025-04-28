#include "bullet_tracers.hpp"

#include "imgui.h"
#include "imgui_internal.h"

#include "game/sdk/unity/camera/camera.hpp"
#include "game/sdk/misc/math/math.hpp"

void c_bullet_tracers::clear( )
{
    m_tracers.clear( );
}

void c_bullet_tracers::push_tracer( const bullet_tracer_t& tracer )
{
    m_tracers.push_back( tracer );
}

void c_bullet_tracers::render( )
{
    if ( m_tracers.size( ) > 100 )
        m_tracers.erase( m_tracers.begin( ) );

    for ( int it { 0 }; it < m_tracers.size( ); it++ )
    {
        bullet_tracer_t& tracer = m_tracers[ it ];

        tracer.alpha_modulate--;

        if ( tracer.alpha_modulate < 1 )
        {
            m_tracers.erase( m_tracers.begin( ) + it );
            continue;
        }

        ImColor const interpolated = ImColor( 1.f, 1.f, 1.f, tracer.alpha_modulate / 255.f );

        w2s_t const start_screen = math::world_to_screen( math::calculate_world_position( tracer.start ) );
        w2s_t const end_screen = math::world_to_screen( math::calculate_world_position( tracer.end ) );

        if ( !start_screen.check && !end_screen.check )
            return;

        ImGui::GetBackgroundDrawList( )->AddLine( start_screen.position, end_screen.position, interpolated );
    }
}