#include "features.hpp"

#include "game/features/ragebot/ragebot.hpp"
#include "game/features/visual/thirdperson/thirdperson.hpp"
#include "game/features/movement/bunnyhop/bunnyhop.hpp"
#include "game/features/misc/peek_assist/peek_assist.hpp"

#include "globals.hpp"

#include "game/sdk/axlebolt/player_controller/player_controller.hpp"

void c_features_manager::process_local_player( c_player_controller* local ) const
{
    if ( !local || !local->alive( ) )
        return;

    g_ctx->features.ragebot->execute( local );
    g_ctx->features.bunnyhop->execute( local );
    g_ctx->features.peek_assist->execute( local );
    g_ctx->features.thirdperson->update( local );
}