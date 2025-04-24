#include "hooks.hpp"

#include "player_controller/late_update/late_update.hpp"
#include "hit_caster/cast_hit/cast_hit.hpp"
#include "player_inputs/get_inputs/get_inputs.hpp"

void c_hooks::hook( ) const
{
    hk::player_controller::late_update::hook( );
    hk::hit_caster::cast_hit::hook( );
    hk::player_inputs::get_inputs::hook( );
}

void c_hooks::unhook( ) const
{
    // TODO
}