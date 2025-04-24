#include "player_inputs.hpp"

#include <cstdint>

bool& c_player_inputs::fire( )
{
    return *reinterpret_cast< bool* >( reinterpret_cast< uintptr_t >( this ) + 0x21 );
}