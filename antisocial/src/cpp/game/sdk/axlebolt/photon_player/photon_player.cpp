#include "photon_player.hpp"

#include "../../unity/unity.hpp"
#include "../../il2cpp/il2cpp.hpp"
#include "../../unity/unity.hpp"

#include "globals.hpp"

std::string c_photon_player::get_nickname( ) const
{
    return ( *reinterpret_cast< unity::string** >( reinterpret_cast< uintptr_t >( this ) + 0x18 ) )->to_cpp_string( );
}

template < typename T >
T c_photon_player::get_property( const std::string& key ) const
{
    if ( !reinterpret_cast< uintptr_t >( this ) )
        return { };

    unity::dictionary< unity::string*, il2cpp_object* >* properties = *reinterpret_cast< unity::dictionary< unity::string*, il2cpp_object* >** >( reinterpret_cast< uintptr_t >( this ) + 0x30 );

    if ( !properties || properties->get_size( ) < 1 )
        return { };

    std::vector< unity::string* > keys = properties->get_keys( );

    if ( keys.empty( ) )
        return { };

    for ( int i { 0 }; i < keys.size( ); i++ )
    {
        if ( keys[ i ]->to_cpp_string( ) != key || !properties->get_values( )[ i ] )
            continue;

        return *( T* ) reinterpret_cast< uintptr_t* ( * ) ( il2cpp_object* ) >( g_ctx->il2cpp->functions.object_unbox )( properties->get_values( )[ i ] );
    }

    return { };
}

template int c_photon_player::get_property< int >( const std::string& ) const;
template float c_photon_player::get_property< float >( const std::string& ) const;
template bool c_photon_player::get_property< bool >( const std::string& ) const;
template char c_photon_player::get_property< char >( const std::string& ) const;
template char* c_photon_player::get_property< char* >( const std::string& ) const;