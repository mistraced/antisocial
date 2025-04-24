#include "bunnyhop.hpp"

#include "game/sdk/axlebolt/player_controller/player_controller.hpp"
#include "game/sdk/misc/obscured.hpp"

#include "globals.hpp"

void c_bunnyhop::execute( c_player_controller* entity ) const
{
    if ( !entity || !entity->alive( ) || !c::get< bool >( g_ctx->cfg.movement_bunnyhop ) )
        return;

    uintptr_t const movement_controller = *reinterpret_cast< uintptr_t* >( reinterpret_cast< uintptr_t >( entity ) + 0xA8 );
    if ( movement_controller )
    {
        uintptr_t const player_translation_parameters = *reinterpret_cast< uintptr_t* >( movement_controller + 0x70 );
        if ( player_translation_parameters )
        {
            uintptr_t const jump_param = *reinterpret_cast< uintptr_t* >( player_translation_parameters + 0x50 );
            uintptr_t const walk_param = *reinterpret_cast< uintptr_t* >( player_translation_parameters + 0x38 );
            uintptr_t const crouch_param = *reinterpret_cast< uintptr_t* >( player_translation_parameters + 0x48 );

            *reinterpret_cast< float* >( player_translation_parameters + 0x28 ) = 999.f;
            auto const jump_ptr = reinterpret_cast< uintptr_t >( jump_param );
            obscured::v_float::set( jump_param + 0xA8, 7.9f );
        }
    }
}