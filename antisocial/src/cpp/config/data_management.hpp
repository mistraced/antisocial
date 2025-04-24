//
// Created by rei on 12/18/23.
//

#pragma once

#include <any>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

#include "fnv1a.hpp"

using fnv1a_t = std::uint32_t;

template < typename T >
class c_variable
{
public:
    std::string name;
    std::shared_ptr< T > value;
    int32_t size;
    c_variable( std::string name, T v )
        : name( name )
    {
        value = std::make_shared< T >( v );
        size = sizeof( T );
    }

    operator T( ) { return *value; }
    operator T*( ) { return &*value; }
    operator T( ) const { return *value; }
};

struct variable_object_t
{
    variable_object_t( const fnv1a_t name_hash, const fnv1a_t type_hash, std::any&& _default )
        : m_name_hash( name_hash )
        , m_type_hash( type_hash )
        , m_value( std::move( _default ) )
    {
    }
    ~variable_object_t( ) = default;
    template < typename T >
    T& get( )
    {
        return *static_cast< T* >( std::any_cast< T >( &m_value ) );
    }
    template < typename T >
    void set( T value )
    {
        m_value.emplace< T >( value );
    }

    fnv1a_t m_name_hash = 0x0;
    fnv1a_t m_type_hash = 0x0;
    std::any m_value = { };
};

namespace c
{
    inline std::vector< variable_object_t > variables = { };
    template < typename T >
    T& get( const std::uint32_t idx )
    {
        return variables.at( idx ).get< T >( );
    }
    template < typename T >
    std::uint32_t add_variable( const fnv1a_t name_hash, const fnv1a_t type_hash, const T _default )
    {
        variables.emplace_back( name_hash, type_hash, std::make_any< T >( _default ) );
        return variables.size( ) - 1U;
    }
} // namespace c

#define declare_variable( type, name, def ) const std::uint32_t name = c::add_variable< type >( fnv1a::hash_const( #name ), fnv1a::hash_const( #type ), def );