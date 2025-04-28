#pragma once

#include "imgui.h"
#include "imgui_internal.h"

#include "game/sdk/structures/vec3.hpp"

struct w2s_t
{
    ImVec2 position;
    bool check;
};

namespace math
{
    extern w2s_t world_to_screen( vec3_t position );
    extern ImRect calculate_player_ent_bbox( vec3_t position, float height );
    extern bool check_surface_by_type( const int type );
    extern void draw_3d_dotted_circle( vec3_t pos, float radius, ImColor color, float segments );
    extern vec3_t calculate_world_position( vec3_t input );
} // namespace math