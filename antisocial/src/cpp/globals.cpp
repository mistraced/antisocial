#include "globals.hpp"

#include "interface/interface.hpp"
#include "game/sdk/il2cpp/il2cpp.hpp"
#include "fonts/fonts.hpp"

#include "game/features/visual/esp/esp.hpp"
#include "game/features/visual/thirdperson/thirdperson.hpp"
#include "game/features/ragebot/ragebot.hpp"
#include "game/features/movement/bunnyhop/bunnyhop.hpp"
#include "game/features/misc/peek_assist/peek_assist.hpp"
#include "game/features/visual/bullet_tracers/bullet_tracers.hpp"

#include "game/features/features.hpp"

#include "game/hooks/hooks.hpp"

void features_t::init( )
{
    esp = c_esp::get( );
    ragebot = c_ragebot::get( );
    thirdperson = c_thirdperson::get( );
    bunnyhop = c_bunnyhop::get( );
    peek_assist = c_peek_assist::get( );
    bullet_tracers = c_bullet_tracers::get( );
}

globals_t::globals_t( )
{
    interface = c_interface::get( );
    il2cpp = c_il2cpp_api::get( );
    fonts = c_fonts::get( );

    features_mgr = c_features_manager::get( );

    hooks = c_hooks::get( );
}