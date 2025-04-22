#pragma once

class c_interface;

struct globals_t
{
    globals_t( );
    ~globals_t( ) = default;

    c_interface* interface;

    bool is_presented = false;
};

extern globals_t* g_ctx;