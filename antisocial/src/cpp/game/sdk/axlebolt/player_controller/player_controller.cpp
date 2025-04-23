#include "player_controller.hpp"

#include "../../unity/transform/transform.hpp"

c_photon_player* c_player_controller::photon_player( ) const
{
    return *reinterpret_cast< c_photon_player** >( reinterpret_cast< uintptr_t >( this ) + 0x108 );
}

team_t c_player_controller::get_team( ) const
{
    return *reinterpret_cast< team_t* >( reinterpret_cast< uintptr_t >( this ) + 0x49 );
}

bool c_player_controller::alive( ) const
{
    // TODO
    return reinterpret_cast< uintptr_t >( this ) && photon_player( );
}

vec3_t c_player_controller::get_position( ) const
{
    return get_transform( )->get_position( );
}