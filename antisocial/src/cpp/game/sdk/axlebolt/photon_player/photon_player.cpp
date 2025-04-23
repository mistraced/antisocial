#include "photon_player.hpp"

#include "../../unity/unity.hpp"

std::string c_photon_player::get_nickname( ) const
{
    return ( *reinterpret_cast< unity::string** >( reinterpret_cast< uintptr_t >( this ) + 0x18 ) )->to_cpp_string( );
}