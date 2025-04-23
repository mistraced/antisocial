#include "biped_map.hpp"

#include "../../unity/transform/transform.hpp"

#include <cstdint>

c_transform* c_biped_map::head( ) const
{
    return *reinterpret_cast< c_transform** >( reinterpret_cast< uintptr_t >( this ) + 0x18 );
}