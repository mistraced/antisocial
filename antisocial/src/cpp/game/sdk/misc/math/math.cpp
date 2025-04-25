#include "math.hpp"

#include "../../unity/camera/camera.hpp"
#include "../../unity/physics/physics.hpp"

w2s_t math::world_to_screen( vec3_t position )
{
    c_camera* const main_camera = c_camera::get_main( );
    if ( !main_camera )
        return w2s_t { ImVec2 { 0, 0 }, 0 };

    vec3_t world_point = main_camera->world_to_viewport( position, 2 );

    world_point.x = static_cast< int >( ImGui::GetIO( ).DisplaySize.x * world_point.x );
    world_point.y = static_cast< int >( ImGui::GetIO( ).DisplaySize.y - world_point.y * ImGui::GetIO( ).DisplaySize.y );

    return w2s_t { ImVec2 { world_point.x, world_point.y }, world_point.z > 0 };
}

ImRect math::calculate_player_ent_bbox( vec3_t position, float height )
{
    ImVec2 const top = world_to_screen( vec3_t( position.x, position.y + height, position.z ) ).position;
    ImVec2 const bottom = world_to_screen( vec3_t( position.x, position.y - 0.15f, position.z ) ).position;

    float calc_top = top.x;
    float calc_bottom = bottom.x;
    if ( top.x > bottom.x )
    {
        calc_top = bottom.x;
        calc_bottom = top.x;
    }

    float const width = abs( ( top.y - bottom.y ) / 2.f ); // abs((top.y - bottom.y) / 3.75f)

    ImVec2 const min = { calc_top - width / 2 - 1, top.y - 1 };

    ImRect const bounds = {
        { static_cast< int >( min.x ),
          static_cast< int >( min.y ) },
        { static_cast< int >( ( calc_bottom + width / 2 + 1 ) ),
          static_cast< int >( ( bottom.y + 1 ) ) } };

    return bounds;
}

bool math::check_surface_by_type( const int type )
{
    return type == surface_type::cardboard ||
           type == surface_type::thin_wood ||
           type == surface_type::glass ||
           type == surface_type::plaster ||
           type == surface_type::wood ||
           type == surface_type::water ||
           type == surface_type::character;
}

void math::draw_3d_dotted_circle( vec3_t pos, float radius, ImColor color, float segments )
{
    for ( float i = 0; i < segments; i++ )
    {
        if ( i < segments )
        {
            vec3_t const pos1 = vec3_t( pos.x + radius * cos( i * ( PI * 2 ) / segments ), pos.y, pos.z + radius * sin( i * ( PI * 2 ) / segments ) );
            vec3_t const pos2 = vec3_t( pos.x + radius * cos( ( i + 1 ) * ( PI * 2 ) / segments ), pos.y, pos.z + radius * sin( ( i + 1 ) * ( PI * 2 ) / segments ) );

            vec3_t const midpoint = vec3_t(
                ( pos1.x + pos2.x ) / 2.0f,
                ( pos1.y + pos2.y ) / 2.0f,
                ( pos1.z + pos2.z ) / 2.0f );

            w2s_t const w2s = world_to_screen( midpoint );

            if ( w2s.check )
                ImGui::GetBackgroundDrawList( )->AddCircleFilled( w2s.position, 3, color, 120 );
        }
    }
}