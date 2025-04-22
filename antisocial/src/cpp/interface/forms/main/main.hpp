#pragma once

class c_main_form
{
public:
    void init( );
    void render( );

    ~c_main_form( ) = default;
    c_main_form( ) = default;
};

namespace forms
{
    extern c_main_form main;
} // namespace forms