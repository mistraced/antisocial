#include "unity.hpp"

#include "game/sdk/il2cpp/il2cpp.hpp"
#include "globals.hpp"

unity::string* create( const char* value )
{
    static auto fn = reinterpret_cast< unity::string* ( * ) ( uintptr_t, const char*, int, int ) >( g_ctx->il2cpp->get_method_pointer( "System", "String", "CreateString", 3 ) );
    return fn( 0, value, 0, strlen( value ) );
}