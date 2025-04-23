#pragma once

#include "imgui.h"
#include "imgui_internal.h"

#include <vector>
#include <string>
#include <functional>

struct esp_element_t
{
    ImVec2 size;
    std::function< void( ImDrawList*, ImVec2 ) > callback;
};

enum class esp_element_side
{
    left,
    right,
    top,
    bottom
};

struct esp_player_data_t
{
    ImRect bounds;
};

class c_esp_player
{
    esp_player_data_t m_data;
    ImDrawList* m_surface;

    std::vector< esp_element_t > m_left, m_top, m_bottom, m_right { };

public:
    ~c_esp_player( ) = default;
    c_esp_player( ) = default;

    explicit c_esp_player( esp_player_data_t data, ImDrawList* surface = ImGui::GetBackgroundDrawList( ) )
        : m_data( data )
        , m_surface( surface ) {};

    void render_rect( ) const;
    void render_elements( ) const;

    void push_element( esp_element_side const& side, esp_element_t const& element );
};