#include "main.hpp"

#include "imgui.h"

#include "game/entities/entities.hpp"

#include "globals.hpp"

c_main_form forms::main { };

void c_main_form::init( )
{
}

void c_main_form::render( )
{
    ImGui::Begin( "antisocial | github.com/mistraced/antisocial" );
    {
        ImGui::Text( "amount of players: %i", c_players_database::get( )->m_players.size( ) );

        ImGui::Checkbox( "esp rect", &g_ctx->cfg.esp_rect );
        ImGui::Checkbox( "esp health", &g_ctx->cfg.esp_health );
        ImGui::Checkbox( "esp nickname", &g_ctx->cfg.esp_nickname );
        ImGui::Checkbox( "esp weapon", &g_ctx->cfg.esp_weapon );
        ImGui::Checkbox( "esp money", &g_ctx->cfg.esp_money );

        ImGui::End( );
    }
}