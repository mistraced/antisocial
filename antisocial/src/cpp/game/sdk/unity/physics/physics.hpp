#pragma once

#include "../../structures/vec3.hpp"

#include "imgui.h"
#include "imgui_internal.h"

struct raycast_hit_t
{
    vec3_t point, normal;
    unsigned int m_face_id;
    float distance;
    ImVec2 ui;
    int m_collider;
};

enum surface_type : uint8_t
{
    unknown = 0,
    glass = 1,
    cardboard = 2,
    metal_grate = 3,
    wood = 4,
    plaster = 5,
    tile = 6,
    metal = 7,
    concrete = 8,
    brick = 9,
    solid_metal = 10,
    thin_metal = 11,
    thin_wood = 12,
    character = 13,
    ground = 14,
    surface_mark_trigger = 15,
    water = 16,
    paper = 17,
    grass = 18,
    gravel = 19,
    grass_no_decal = 20
};

class c_surface_mark_trigger
{
public:
};

class c_component;

namespace unity
{
    struct string;
}

class c_physics
{
public:
    static float get_penetration_loss( int type, float thickness );
    static bool linecast( vec3_t start, vec3_t end, int mask );
    static bool linecast( vec3_t start, vec3_t end, raycast_hit_t* ray, int mask );
    static c_component* raycast_get_collider( raycast_hit_t* ray );
    static surface_type surface_from_tag( unity::string* tag );
};