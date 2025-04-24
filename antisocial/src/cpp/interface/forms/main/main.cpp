#include "main.hpp"

#include "imgui.h"

#include "game/entities/entities.hpp"

#include "game/sdk/structures/vec3.hpp"

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

        ImGui::Checkbox( "esp rect", &c::get< bool >( g_ctx->cfg.esp_rect ) );
        ImGui::Checkbox( "esp health", &c::get< bool >( g_ctx->cfg.esp_health ) );
        ImGui::Checkbox( "esp nickname", &c::get< bool >( g_ctx->cfg.esp_nickname ) );
        ImGui::Checkbox( "esp weapon", &c::get< bool >( g_ctx->cfg.esp_weapon ) );
        ImGui::Checkbox( "esp money", &c::get< bool >( g_ctx->cfg.esp_money ) );

        ImGui::Checkbox( "ragebot enabled", &c::get< bool >( g_ctx->cfg.ragebot_enabled ) );
        ImGui::Checkbox( "ragebot silent", &c::get< bool >( g_ctx->cfg.ragebot_silent ) );
        ImGui::Checkbox( "ragebot triggerbot", &c::get< bool >( g_ctx->cfg.ragebot_triggerbot ) );
        ImGui::Checkbox( "ragebot antiaim", &c::get< bool >( g_ctx->cfg.ragebot_antiaim ) );

        ImGui::SliderFloat( "antiaim rot x", &c::get< vec3_t >( g_ctx->cfg.antiaim_rotation ).x, -180, 180 );
        ImGui::SliderFloat( "antiaim rot y", &c::get< vec3_t >( g_ctx->cfg.antiaim_rotation ).y, -180, 180 );
        ImGui::SliderFloat( "antiaim rot z", &c::get< vec3_t >( g_ctx->cfg.antiaim_rotation ).z, -180, 180 );

        ImGui::SliderFloat( "antiaim sub x", &c::get< vec3_t >( g_ctx->cfg.antiaim_substitute ).x, -180, 180 );
        ImGui::SliderFloat( "antiaim sub y", &c::get< vec3_t >( g_ctx->cfg.antiaim_substitute ).y, -180, 180 );
        ImGui::SliderFloat( "antiaim sub z", &c::get< vec3_t >( g_ctx->cfg.antiaim_substitute ).z, -180, 180 );

        ImGui::Checkbox( "thirdperson", &c::get< bool >( g_ctx->cfg.misc_thirdperson ) );

        ImGui::Checkbox( "bunnyhop", &c::get< bool >( g_ctx->cfg.movement_bunnyhop ) );

        ImGui::End( );
    }
}