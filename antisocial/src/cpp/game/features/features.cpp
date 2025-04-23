#include "features.hpp"

#include "game/features/ragebot/ragebot.hpp"

#include "globals.hpp"

#include "game/sdk/axlebolt/player_controller/player_controller.hpp"

void c_features_manager::process_local_player( c_player_controller* local ) const
{
    if ( !local || !local->alive( ) )
        return;

    g_ctx->features.ragebot->execute( local );
}