#include "players.hpp"

void c_esp_player::render_rect( ) const
{
    int const width = std::min( static_cast< int >( m_data.bounds.GetWidth( ) / 10.f ), 1 );

    ImColor const primary_color = ImColor( 255, 255, 255 );
    ImColor const secondary_color = ImColor( 207, 45, 75 );

    m_surface->AddShadowRect( { m_data.bounds.GetCenter( ).x - width / 2, m_data.bounds.Min.y }, { m_data.bounds.GetCenter( ).x + width / 2, m_data.bounds.Max.y }, primary_color, width * 4, { 0, 0 }, width * 4 );

    m_surface->AddShadowRect( { m_data.bounds.Min.x + width, m_data.bounds.GetCenter( ).y - width / 2 }, { m_data.bounds.Max.x - width, m_data.bounds.GetCenter( ).y + width / 2 }, primary_color, width * 4, { 0, 0 }, width * 4 );

    m_surface->AddShadowCircle( m_data.bounds.GetCenter( ), width / 2, secondary_color, width * 30, { 0, 0 }, 0, 400 );

    m_surface->AddLine( { m_data.bounds.GetCenter( ).x, m_data.bounds.Min.y }, { m_data.bounds.GetCenter( ).x, m_data.bounds.Max.y }, primary_color, width );
    m_surface->AddLine( { m_data.bounds.Min.x + width, m_data.bounds.GetCenter( ).y }, { m_data.bounds.Max.x - width, m_data.bounds.GetCenter( ).y }, primary_color, width );
    m_surface->AddLine( { m_data.bounds.Min.x, m_data.bounds.GetCenter( ).y - m_data.bounds.GetHeight( ) / 4 }, { m_data.bounds.Max.x, m_data.bounds.GetCenter( ).y - m_data.bounds.GetHeight( ) / 4 }, primary_color, width );
    m_surface->AddLine( { m_data.bounds.Min.x, m_data.bounds.GetCenter( ).y + m_data.bounds.GetHeight( ) / 4 }, { m_data.bounds.Max.x, m_data.bounds.GetCenter( ).y + m_data.bounds.GetHeight( ) / 4 }, primary_color, width );
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