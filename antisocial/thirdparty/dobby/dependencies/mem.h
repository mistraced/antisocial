#import <mach-o/dyld.h>
#import <mach/mach.h>
#import <mach/mach_init.h>
#import <dlfcn.h>
#import <stdio.h>
#import <string>

typedef long kaddr;

bool _read( kaddr addr, void* buffer, int len )
{
    vm_size_t size = 0;
    kern_return_t error = vm_read_overwrite( mach_task_self( ), ( vm_address_t ) addr, len, ( vm_address_t ) buffer, &size );
    if ( error != KERN_SUCCESS || size != len )
    {
        return false;
    }
    return true;
}

template < typename T >
T Read( kaddr address )
{
    T data;
    _read( address, reinterpret_cast< void* >( &data ), sizeof( T ) );
    return data;
}

void* GetPtr( kaddr address )
{
    return Read< void* >( address );
}