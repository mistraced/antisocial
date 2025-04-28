#pragma once

#include "singleton.hpp"

class c_hooks : public singleton< c_hooks >
{
public:
    ~c_hooks( ) = default;
    c_hooks( ) = default;

    void hook( ) const;
    void unhook( ) const;
};