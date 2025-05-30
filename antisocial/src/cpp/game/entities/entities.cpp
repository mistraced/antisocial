#include "entities.hpp"

#include "game/sdk/axlebolt/player_manager/player_manager.hpp"
#include "game/sdk/axlebolt/player_controller/player_controller.hpp"
#include "game/sdk/axlebolt/biped_map/biped_map.hpp"
#include "game/sdk/axlebolt/weapon_controller/weapon_controller.hpp"
#include "game/sdk/axlebolt/photon_player/photon_player.hpp"
#include "game/sdk/unity/physics/physics.hpp"
#include "game/sdk/unity/transform/transform.hpp"
#include "game/sdk/unity/camera/camera.hpp"
#include "game/sdk/unity/physics/physics.hpp"
#include "game/sdk/unity/unity.hpp"
#include "game/sdk/misc/math/math.hpp"

#include "game/features/features.hpp"

#include "game/features/visual/thirdperson/thirdperson.hpp"
#include "game/features/visual/esp/esp.hpp"
#include "game/features/misc/peek_assist/peek_assist.hpp"
#include "game/features/visual/bullet_tracers/bullet_tracers.hpp"

#include "game/features/ragebot/ragebot.hpp"

#include "globals.hpp"

void c_players_database::update( )
{
    auto const clear_data = [ & ]( ) -> void {
        m_players.clear( );
        g_ctx->features.bullet_tracers->clear( );
        m_local_player = nullptr;
        g_ctx->features.ragebot->m_target = nullptr;
        g_ctx->features.peek_assist->m_peeking = false;
        g_ctx->features.peek_assist->m_peeked = false;
    };

    auto* const player_manager = c_player_manager::get_instance( );
    if ( !player_manager )
    {
        clear_data( );
        return;
    }

    m_local_player = player_manager->get_local_player( );
    if ( !m_local_player || !m_local_player->alive( ) )
    {
        clear_data( );
        return;
    }

    m_local_player->fix_occlusion( );

    m_players = player_manager->get_players( );

    c_local_player::m_team = m_local_player->get_team( );

    // let's also process them there for now
    for ( auto* const entity : m_players )
    {
        if ( !entity || !entity->alive( ) )
            continue;

        entity->fix_occlusion( );

        g_ctx->features.esp->process_ent_player( entity );
    }

    g_ctx->features_mgr->process_local_player( m_local_player );

    g_ctx->features.bullet_tracers->render( );
}

c_player_controller* c_players_database::get_ragebot_entity( ) const
{
    vec3_t const view_position = g_ctx->features.thirdperson->get_unmodified_view( );

    auto* const local = m_local_player;
    if ( !local || !local->alive( ) )
        return nullptr;

    auto* const weapon = local->get_weapon( );
    if ( !weapon || !weapon->is_gun( weapon->get_id( ) ) )
        return nullptr;

    auto* const gun = weapon->get_gun( );
    if ( !gun )
        return nullptr;

    for ( auto* const entity : m_players )
    {
        if ( !entity || !entity->alive( ) )
            continue;

        c_photon_player* const photon = entity->photon_player( );
        if ( !photon || photon->get_property< bool >( "untouchable" ) )
            continue;

        c_biped_map* const biped_map = entity->biped_map( );
        if ( !biped_map )
            continue;

        auto* const bone = g_ctx->features.ragebot->select_bone( biped_map, view_position, gun );
        if ( !bone )
            continue;

        bool const visible = !c_physics::linecast( view_position, bone->get_position( ), 16384 );

        bool const wallbang = [ & ]( ) -> bool {
            if ( !c::get< bool >( g_ctx->cfg.ragebot_autowall ) )
                return false;

            raycast_hit_t hit;
            if ( !c_physics::linecast( view_position, bone->get_position( ), &hit, 16384 ) )
                return false;

            c_component* const collider = c_physics::raycast_get_collider( &hit );

            if ( !collider )
                return false;

            unity::string* const surface_tag = collider->get_tag( );
            if ( !surface_tag )
                return false;

            std::string const surface_name = surface_tag->to_cpp_string( );
            int const surface_type = c_physics::surface_from_tag( surface_tag );

            if ( math::check_surface_by_type( surface_type ) && surface_type != surface_mark_trigger )
                return true;

            return false;
        }( );

        if ( !visible && !wallbang )
            continue;

        return entity;
    }

    return nullptr;
}