#include "player_controller.hpp"

#include "../../unity/transform/transform.hpp"
#include "../../il2cpp/il2cpp.hpp"
#include "../../unity/unity.hpp"

#include "../photon_player/photon_player.hpp"

#include "globals.hpp"

c_photon_player* c_player_controller::photon_player( ) const
{
    return *reinterpret_cast< c_photon_player** >( reinterpret_cast< uintptr_t >( this ) + 0x108 );
}

team_t c_player_controller::get_team( ) const
{
    return *reinterpret_cast< team_t* >( reinterpret_cast< uintptr_t >( this ) + 0x49 );
}

int c_player_controller::get_health( ) const
{
    return photon_player( )->get_property< int >( "health" );
}

bool c_player_controller::alive( ) const
{
    // TODO
    return reinterpret_cast< uintptr_t >( this ) && photon_player( ) && get_health( ) > 0;
}

vec3_t c_player_controller::get_position( ) const
{
    return get_transform( )->get_position( );
}

std::string c_player_controller::get_weapon_name( ) const
{
    uintptr_t const weaponry = *reinterpret_cast< uintptr_t* >( reinterpret_cast< uintptr_t >( this ) + 0x98 );
    if ( !weaponry )
        return "-";

    uintptr_t const weapon = *reinterpret_cast< uintptr_t* >( weaponry + 0x90 );
    if ( !weapon )
        return "-";

    uintptr_t const parameters = *reinterpret_cast< uintptr_t* >( weapon + 0x98 );
    if ( !parameters )
        return "-";

    return ( *reinterpret_cast< unity::string** >( parameters + 0x20 ) )->to_cpp_string( );
}