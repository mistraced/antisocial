#pragma once

#include "game/sdk/structures/vec3.hpp"

#include "config/data.hpp"

class c_interface;
class c_il2cpp_api;
class c_fonts;

class c_esp;
class c_ragebot;
class c_thirdperson;
class c_bunnyhop;
class c_peek_assist;

class c_features_manager;

class c_hooks;

struct features_t
{
    c_esp* esp;
    c_ragebot* ragebot;
    c_thirdperson* thirdperson;
    c_bunnyhop* bunnyhop;
    c_peek_assist* peek_assist;

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

    c_features_manager* features_mgr;

    c_hooks* hooks;

    bool is_presented = false;
};

extern globals_t* g_ctx;