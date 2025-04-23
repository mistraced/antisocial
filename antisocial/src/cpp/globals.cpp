#include "globals.hpp"

#include "interface/interface.hpp"
#include "game/sdk/il2cpp/il2cpp.hpp"
#include "fonts/fonts.hpp"

#include "game/features/visual/esp/esp.hpp"
#include "game/features/ragebot/ragebot.hpp"

#include "game/features/features.hpp"

void features_t::init( )
{
    esp = c_esp::get( );
    ragebot = c_ragebot::get( );
}

globals_t::globals_t( )
{
    interface = c_interface::get( );
    il2cpp = c_il2cpp_api::get( );
    fonts = c_fonts::get( );

    features_mgr = c_features_manager::get( );
}