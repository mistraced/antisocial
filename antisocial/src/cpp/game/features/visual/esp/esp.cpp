#include "esp.hpp"

#include "game/sdk/axlebolt/player_controller/player_controller.hpp"
#include "game/sdk/misc/math/math.hpp"

#include "players/players.hpp"

void c_esp::process_ent_player( c_player_controller* entity ) const
{
    if ( !entity || !entity->alive( ) )
        return;

    auto const screen = math::world_to_screen( entity->get_position( ) );
    if ( !screen.check )
        return;

    ImRect const bounds = math::calculate_player_ent_bbox( entity->get_position( ), 1.8f );

    c_esp_player const esp( { bounds } );
    esp.render_rect( );
}