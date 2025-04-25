#include "peek_assist.hpp"

#include "game/sdk/axlebolt/player_controller/player_controller.hpp"
#include "game/sdk/unity/transform/transform.hpp"
#include "game/sdk/misc/math/math.hpp"

#include "globals.hpp"

void c_peek_assist::execute( c_player_controller* local )
{
    if ( !local || !local->alive( ) || !c::get< bool >( g_ctx->cfg.misc_peek_assist ) )
        return;

    if ( !m_peeking )
    {
        if ( m_peeked )
        {
            while ( m_last_pos != local->get_position( ) )
                local->get_transform( )->set_position( m_last_pos );

            m_peeked = false;
        }

        return;
    }

    if ( !m_peeked )
        m_last_pos = local->get_position( );

    math::draw_3d_dotted_circle( m_last_pos, 0.6f, ImColor( 255, 255, 255 ), 14 );

    m_peeked = true;
}
