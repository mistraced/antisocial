#pragma once

#include <cstdint>

class c_aiming_data
{
public:
    template < typename T >
    T& cur_aim_ang( )
    {
        return *reinterpret_cast< T* >( reinterpret_cast< uintptr_t >( this ) + 0x18 );
    }

    template < typename T >
    T& cur_euler_ang( )
    {
        return *reinterpret_cast< T* >( reinterpret_cast< uintptr_t >( this ) + 0x24 );
    }
};