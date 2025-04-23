#include "players.hpp"

void c_esp_player::render_rect( ) const
{
    m_surface->AddRect( m_data.bounds.Min + ImVec2( 1, 1 ), m_data.bounds.Max - ImVec2( 1, 1 ), ImColor( 0, 0, 0, 120 ) );
    m_surface->AddRect( m_data.bounds.Min - ImVec2( 1, 1 ), m_data.bounds.Max + ImVec2( 1, 1 ), ImColor( 0, 0, 0, 120 ) );

    m_surface->AddRect( m_data.bounds.Min, m_data.bounds.Max, ImColor( 255, 255, 255, 220 ) );
}