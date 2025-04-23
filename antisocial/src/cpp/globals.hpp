#pragma once

#include "game/sdk/structures/vec3.hpp"

#include "config/data.hpp"

class c_interface;
class c_il2cpp_api;
class c_fonts;

class c_esp;

struct features_t
{
    c_esp* esp;

    void init( );

    features_t( ) = default;
    ~features_t( ) = default;
};

struct globals_t
{
    globals_t( );
    ~globals_t( ) = default;

    c_interface* interface;
    c_il2cpp_api* il2cpp;
    c_fonts* fonts;

    cfg_t cfg;
    features_t features;

    bool is_presented = false;
};

extern globals_t* g_ctx;