#pragma once

#include "imgui.h"
#include "imgui_internal.h"

#include "singleton.hpp"

struct font_t
{
    ImFont* ptr;
    float size;
};

class c_fonts : public singleton< c_fonts >
{
public:
    font_t primary;

    void initialize( );
};