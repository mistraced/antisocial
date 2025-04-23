#pragma once

#include "game/sdk/il2cpp/il2cpp.hpp"

#include <string>

class c_photon_player
{
public:
    std::string get_nickname( ) const;

    template < typename T >
    T get_property( const std::string& key ) const;
};
