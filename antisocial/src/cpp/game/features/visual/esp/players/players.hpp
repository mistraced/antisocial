#pragma once

#include "imgui.h"
#include "imgui_internal.h"

struct esp_player_data_t
{
    ImRect bounds;
};

class c_esp_player
{
    esp_player_data_t m_data;
    ImDrawList* m_surface;

public:
    ~c_esp_player( ) = default;
    c_esp_player( ) = default;

    explicit c_esp_player( esp_player_data_t data, ImDrawList* surface = ImGui::GetBackgroundDrawList( ) )
        : m_data( data )
        , m_surface( surface ) {};

    void render_rect( ) const;
};