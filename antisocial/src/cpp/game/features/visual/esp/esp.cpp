#include "esp.hpp"

#include "game/sdk/axlebolt/player_controller/player_controller.hpp"
#include "game/sdk/axlebolt/photon_player/photon_player.hpp"
#include "game/sdk/misc/math/math.hpp"

#include "players/players.hpp"

#include "fonts/fonts.hpp"

#include "globals.hpp"

void c_esp::process_ent_player( c_player_controller* entity ) const
{
    if ( !entity || !entity->alive( ) )
        return;

    auto const screen = math::world_to_screen( entity->get_position( ) );
    if ( !screen.check )
        return;

    c_photon_player* const photon = entity->photon_player( );
    if ( !photon )
        return;

    ImRect const bounds = math::calculate_player_ent_bbox( entity->get_position( ), 1.8f );

    c_esp_player esp( { bounds } );
    esp.render_rect( );

    // health and ammo rn isn't parsed

    esp.push_element( esp_element_side::left, { { 5, 0 }, [ bounds ]( ImDrawList* surface, ImVec2 cursor_pos ) -> void {
                                                   surface->AddRectFilled( { cursor_pos.x - 5, bounds.Min.y }, { cursor_pos.x - 3, bounds.Max.y }, ImColor( 255, 0, 0 ) );
                                                   surface->AddRect( { cursor_pos.x - 6, bounds.Min.y - 1 }, { cursor_pos.x - 2, bounds.Max.y + 1 }, ImColor( 0, 0, 0 ) );
                                               } } );

    esp.push_element( esp_element_side::bottom, { { 0, 5 }, [ bounds ]( ImDrawList* surface, ImVec2 cursor_pos ) -> void {
                                                     surface->AddRectFilled( { bounds.Min.x, cursor_pos.y + 3 }, { bounds.Max.x, cursor_pos.y + 5 }, ImColor( 0, 255, 0 ) );
                                                     surface->AddRect( { bounds.Min.x - 1, cursor_pos.y + 2 }, { bounds.Max.x + 1, cursor_pos.y + 6 }, ImColor( 0, 0, 0 ) );
                                                 } } );

    std::string const nickname = photon->get_nickname( );
    ImVec2 const nickname_size = g_ctx->fonts->primary.ptr->CalcTextSizeA( g_ctx->fonts->primary.size, FLT_MAX, -1, nickname.c_str( ) );

    esp.push_element( esp_element_side::top, { nickname_size, [ bounds, nickname_size, nickname ]( ImDrawList* surface, ImVec2 cursor_pos ) -> void {
                                                  surface->AddText( g_ctx->fonts->primary.ptr, g_ctx->fonts->primary.size, cursor_pos - ImVec2( nickname_size.x / 2, nickname_size.y + 2 ), ImColor( 255, 255, 255 ), nickname.c_str( ) );
                                              } } );

    std::string const weapon = "weapon_placeholder";
    ImVec2 const weapon_size = g_ctx->fonts->primary.ptr->CalcTextSizeA( g_ctx->fonts->primary.size, FLT_MAX, -1, weapon.c_str( ) );

    esp.push_element( esp_element_side::bottom, { weapon_size, [ bounds, weapon_size, weapon ]( ImDrawList* surface, ImVec2 cursor_pos ) -> void {
                                                     surface->AddText( g_ctx->fonts->primary.ptr, g_ctx->fonts->primary.size, cursor_pos - ImVec2( weapon_size.x / 2, 0 ), ImColor( 255, 255, 255 ), weapon.c_str( ) );
                                                 } } );

    esp.render_rect( );
    esp.render_elements( );
}