#include "gun_controller.hpp"

#include <cstdint>

float& c_gun_controller::time_fired( )
{
    return *reinterpret_cast< float* >( reinterpret_cast< uintptr_t >( this ) + 0x180 );
}

int c_gun_controller::get_damage( gun_damage_t type ) const
{
    if ( !reinterpret_cast< uintptr_t >( this ) )
        return 0;

    uintptr_t const param = *reinterpret_cast< uintptr_t* >( reinterpret_cast< uintptr_t >( this ) + 0x190 );
    if ( !param )
        return 0;

    uintptr_t const damage = *reinterpret_cast< uintptr_t* >( param + 0x88 );
    if ( !damage )
        return 0;

    return [ damage, type ]( ) -> int {
        switch ( type )
        {
        case gun_damage_t::head:
            return *reinterpret_cast< int* >( damage + 0x10 );
        case gun_damage_t::body:
            return *reinterpret_cast< int* >( damage + 0x14 );
        case gun_damage_t::arms:
            return *reinterpret_cast< int* >( damage + 0x18 );
        case gun_damage_t::legs:
            return *reinterpret_cast< int* >( damage + 0x1C );
        default:
            return 0;
        };
    }( );
}