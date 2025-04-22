#include "memory_manager.hpp"

uintptr_t memory_manager::base = 0;

uintptr_t memory_manager::get_absolute( uintptr_t relative )
{
    return base + relative;
}