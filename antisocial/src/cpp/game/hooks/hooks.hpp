#pragma once

#include "singleton.hpp"

class c_hooks : public singleton< c_hooks >
{
public:
    void hook( ) const;
    void unhook( ) const;
};