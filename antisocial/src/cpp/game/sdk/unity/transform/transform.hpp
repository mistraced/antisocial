#pragma once

#include "../../structures/vec3.hpp"

class c_transform
{
public:
    vec3_t get_position( ) const;
    vec3_t get_forward( ) const;
    vec3_t get_up( ) const;
    void set_position( vec3_t position ) const;
    void set_local_euler( vec3_t rotation ) const;
};