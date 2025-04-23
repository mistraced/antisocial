#include "player_manager.hpp"

#include "game/sdk/il2cpp/il2cpp.hpp"
#include "game/sdk/unity/unity.hpp"

#include "../player_controller/player_controller.hpp"
#include "../local_player/local_player.hpp"

#include "globals.hpp"

uintptr_t c_player_manager::m_networking_peer { 0 };
uintptr_t c_player_manager::m_lazy_api { 0 };
uintptr_t c_player_manager::m_game_api { 0 };

c_player_manager* c_player_manager::get_instance( )
{
    if ( !m_networking_peer || !m_lazy_api )
    {
        uintptr_t const photon_network_class = reinterpret_cast< uintptr_t >( g_ctx->il2cpp->get_class( "", "PhotonNetwork" ) );
        uintptr_t const manager_class = reinterpret_cast< uintptr_t >( g_ctx->il2cpp->get_class( "Axlebolt.Standoff.Player", "PlayerManager" ) );

        if ( !manager_class || !photon_network_class )
            return 0;

        m_networking_peer = reinterpret_cast< uintptr_t ( * )( uintptr_t, const char* ) >( g_ctx->il2cpp->functions.class_get_field_from_name )( photon_network_class, "networkingPeer" );
        m_lazy_api = reinterpret_cast< uintptr_t ( * )( uintptr_t, const char* ) >( g_ctx->il2cpp->functions.class_get_field_from_name )( manager_class, "_instance" );
    }

    c_player_manager* ret;
    reinterpret_cast< void ( * )( uintptr_t, void** ) >( g_ctx->il2cpp->functions.field_static_get_value )( m_lazy_api, reinterpret_cast< void** >( &ret ) );
    return ret;
}

c_local_player* c_player_manager::get_local_player( ) const
{
    return *reinterpret_cast< c_local_player** >( reinterpret_cast< uintptr_t >( this ) + 0x40 );
}

std::vector< c_player_controller* > c_player_manager::get_players( ) const
{
    std::vector< c_player_controller* > ret;

    if ( !reinterpret_cast< uintptr_t >( this ) )
        return { };

    c_player_controller* const local = get_local_player( );
    if ( !reinterpret_cast< uintptr_t >( local ) )
        return { };

    auto const list = *reinterpret_cast< unity::dictionary< int, c_player_controller* >** >( reinterpret_cast< uintptr_t >( this ) + 0x20 );
    if ( !list )
        return { };

    for ( size_t idx { 0 }; idx < list->get_size( ); idx++ )
    {
        c_player_controller* const player = list->get_values( )[ idx ];
        if ( !player )
            continue;

        c_photon_player* const photon = player->photon_player( );
        if ( !photon || !player->alive( ) )
            continue;

        if ( player->get_team( ) == c_local_player::m_team )
            continue;

        if ( std::find( ret.begin( ), ret.end( ), player ) == ret.end( ) )
            ret.push_back( player );
    }

    return std::move( ret );
}