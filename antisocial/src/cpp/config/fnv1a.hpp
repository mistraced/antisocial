#pragma once

#include <cstdint>
#include <cstdlib>
#include <cstring>

using fnv1a_t = std::uint32_t;

/*
 * @credits: underscorediscovery
 */
namespace fnv1a
{
    constexpr std::uint32_t ull_basis = 0x811C9DC5;
    constexpr std::uint32_t ull_prime = 0x1000193;

    constexpr fnv1a_t hash_const( const char* string, const fnv1a_t value = ull_basis ) noexcept
    {
        return ( string[ 0 ] == '\0' ) ? value : hash_const( &string[ 1 ], ( value ^ static_cast< fnv1a_t >( string[ 0 ] ) ) * ull_prime );
    }

    inline fnv1a_t hash( const char* string, fnv1a_t value = ull_basis )
    {
        for ( size_t i = 0; i < strlen( string ); ++i )
        {
            value ^= string[ i ];
            value *= ull_prime;
        }

        return value;
    }
} // namespace fnv1a