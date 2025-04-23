#include "main.hpp"

#include "imgui.h"

#include "game/entities/entities.hpp"

c_main_form forms::main { };

void c_main_form::init( )
{
}

void c_main_form::render( )
{
    ImGui::Begin( "antisocial | github.com/mistraced/antisocial" );
    {
        ImGui::Text( "amount of players: %i", c_players_database::get( )->m_players.size( ) );

        ImGui::End( );
    }
}