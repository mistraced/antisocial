#pragma once

#include <cstdint>

namespace memory_manager
{
    extern uintptr_t base;

    // objc
    extern uintptr_t get_base( );
    extern void hook( uintptr_t address, void* modified, void** original );

    extern uintptr_t get_absolute( uintptr_t relative );
} // namespace memory_manager