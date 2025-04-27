#include "weapon_controller.hpp"

#include "../gun_controller/gun_controller.hpp"

#include "game/sdk/unity/unity.hpp"

bool c_weapon_controller::is_gun( int id ) const
{
    return id >= 11 && id <= 65;
}

int c_weapon_controller::get_id( ) const
{
    uintptr_t const parameters = *reinterpret_cast< uintptr_t* >( reinterpret_cast< uintptr_t >( this ) + 0x98 );
    if ( !parameters )
        return 0;

    return *reinterpret_cast< int* >( parameters + 0x18 );
}

c_gun_controller* c_weapon_controller::get_gun( )
{
    return reinterpret_cast< c_gun_controller* >( this );
}

uintptr_t c_weapon_controller::get_commands( ) const
{
    return *reinterpret_cast< uintptr_t* >( reinterpret_cast< uintptr_t >( this ) + 0x68 );
}

std::string c_weapon_controller::get_name( ) const
{
    uintptr_t const parameters = *reinterpret_cast< uintptr_t* >( reinterpret_cast< uintptr_t >( this ) + 0x98 );
    if ( !parameters )
        return "null";

    return ( *reinterpret_cast< unity::string** >( parameters + 0x20 ) )->to_cpp_string( );
}