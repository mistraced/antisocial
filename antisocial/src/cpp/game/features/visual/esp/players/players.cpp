#include "players.hpp"

void c_esp_player::render_rect( ) const
{
    m_surface->AddRect( m_data.bounds.Min + ImVec2( 1, 1 ), m_data.bounds.Max - ImVec2( 1, 1 ), ImColor( 0, 0, 0, 120 ) );
    m_surface->AddRect( m_data.bounds.Min - ImVec2( 1, 1 ), m_data.bounds.Max + ImVec2( 1, 1 ), ImColor( 0, 0, 0, 120 ) );

    m_surface->AddRect( m_data.bounds.Min, m_data.bounds.Max, ImColor( 255, 255, 255, 220 ) );
}

void c_esp_player::render_elements( ) const
{
    // might also add default padding later so I made cursor_pos like this

    auto const right = [ this ]( ) -> void {
        ImVec2 cursor_pos = ImVec2 { m_data.bounds.Max.x, m_data.bounds.Min.y - 2 };

        for ( const auto& elem : m_right )
        {
            if ( elem.callback )
                elem.callback( m_surface, cursor_pos );

            cursor_pos = ImVec2 { cursor_pos.x + elem.size.x, cursor_pos.y + elem.size.y };
        }
    };

    auto const left = [ this ]( ) -> void {
        ImVec2 cursor_pos = ImVec2 { m_data.bounds.Min.x, m_data.bounds.Min.y - 2 };

        for ( const auto& elem : m_left )
        {
            if ( elem.callback )
                elem.callback( m_surface, cursor_pos );

            cursor_pos = ImVec2 { cursor_pos.x - elem.size.x, cursor_pos.y + elem.size.y };
        }
    };

    auto const top = [ this ]( ) -> void {
        ImVec2 cursor_pos = ImVec2 { m_data.bounds.GetCenter( ).x, m_data.bounds.Min.y };

        for ( const auto& elem : m_top )
        {
            if ( elem.callback )
                elem.callback( m_surface, cursor_pos );

            cursor_pos.y -= elem.size.y;
        }
    };

    auto const bottom = [ this ]( ) -> void {
        ImVec2 cursor_pos = ImVec2 { m_data.bounds.GetCenter( ).x, m_data.bounds.Max.y };

        for ( const auto& elem : m_bottom )
        {
            if ( elem.callback )
                elem.callback( m_surface, cursor_pos );

            cursor_pos.y += elem.size.y;
        }
    };

    right( );
    left( );

    top( );
    bottom( );
}

void c_esp_player::push_element( esp_element_side const& side, esp_element_t const& element )
{
    switch ( side )
    {
    case esp_element_side::bottom:
        m_bottom.push_back( element );
        break;
    case esp_element_side::top:
        m_top.push_back( element );
        break;
    case esp_element_side::left:
        m_left.push_back( element );
        break;
    case esp_element_side::right:
        m_right.push_back( element );
        break;
    default:
        break;
    }
}