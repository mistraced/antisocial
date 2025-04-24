#pragma once

#include <cstdint>

namespace obscured
{
    namespace v_float
    {
        inline void set( uint64_t location, float value )
        {
            int crypto_key = *reinterpret_cast< int* >( location );

            union intfloat
            {
                int i;
                float f;
            };

            intfloat IF;
            IF.f = value;
            intfloat IF2;
            IF2.i = IF.i ^ crypto_key;

            *reinterpret_cast< float* >( location + 0x4 ) = IF2.f;
        }
    } // namespace v_float
} // namespace obscured
