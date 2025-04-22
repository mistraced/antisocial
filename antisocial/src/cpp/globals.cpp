#include "globals.hpp"

#include "interface/interface.hpp"

globals_t::globals_t( )
{
    interface = c_interface::get( );
}