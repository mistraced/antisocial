#include "globals.hpp"

#include "interface/interface.hpp"
#include "game/sdk/il2cpp/il2cpp.hpp"

#include "game/features/visual/esp/esp.hpp"

void features_t::init( )
{
    esp = c_esp::get( );
}

globals_t::globals_t( )
{
    interface = c_interface::get( );
    il2cpp = c_il2cpp_api::get( );
}