#pragma once

#include <cmath>
#include <codecvt>
#include <fstream>
#include <functional>
#include <locale>
#include <map>
#include <sstream>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

namespace unity
{
    template < typename T >
    struct array
    {
        void* klass;
        void* monitor;
        void* bounds;
        int32_t capacity;
        T m_items[ 0 ];

        [[maybe_unused]] int32_t get_capacity( )
        {
            if ( !this )
                return 0;

            return capacity;
        }

        T* get_ptr( )
        {
            if ( !this )
                return nullptr;

            return m_items;
        }

        std::vector< T > to_cpp_array( )
        {
            if ( !this )
                return { };

            std::vector< T > ret;

            for ( int i = 0; i < capacity; i++ )
                ret.push_back( m_items[ i ] );

            return std::move( ret );
        }

        bool copy_from( const std::vector< T >& vec )
        {
            if ( !this )
                return false;

            return copy_from( ( T* ) vec.data( ), ( int ) vec.size( ) );
        }

        [[maybe_unused]] bool copy_from( T* arr, int size )
        {
            if ( !this )
                return false;

            if ( size < capacity )
                return false;

            memcpy( m_items, arr, size * sizeof( T ) );

            return true;
        }

        [[maybe_unused]] void copy_to( T* arr )
        {
            if ( !this || !check_obj( m_items ) )
                return;

            memcpy( arr, m_items, sizeof( T ) * capacity );
        }

        T& operator[]( int index )
        {
            if ( get_capacity( ) < index )
            {
                T a { };
                return a;
            }

            return m_items[ index ];
        }

        T& at( int index )
        {
            if ( !this || get_capacity( ) <= index || empty( ) )
            {
                T a { };
                return a;
            }

            return m_items[ index ];
        }

        bool empty( )
        {
            if ( !this )
                return false;

            return get_capacity( ) <= 0;
        }

        static array< T >* create( int capacity )
        {
            auto arr = ( array< T >* ) malloc( sizeof( array ) + sizeof( T ) * capacity );
            arr->capacity = capacity;

            return arr;
        }

        [[maybe_unused]] static array< T >* create( const std::vector< T >& vec )
        {
            return create( vec.data( ), vec.size( ) );
        }

        static array< T >* create( T* arr, int size )
        {
            array< T >* arr_ = create( size );
            arr_->copy_from( arr, size );

            return arr_;
        }
    };

    struct string
    {
        void* klass;
        void* monitor;
        int length;
        char chars[ 1 ];

        int get_length( )
        {
            return length;
        }

        char* get_chars( )
        {
            return chars;
        }

        std::string to_cpp_string( )
        {
            if ( !reinterpret_cast< uintptr_t >( this ) ) // 5000$ crash fix sln
                return "";

            std::u16string utf16_string( reinterpret_cast< const char16_t* >( chars ), length );

            std::wstring_convert< std::codecvt_utf8_utf16< char16_t >, char16_t > converter;
            std::string utf8_string = converter.to_bytes( utf16_string );

            return utf8_string;
        }

        const char* to_cstring( )
        {
            if ( !reinterpret_cast< uintptr_t >( this ) ) // 5000$ crash fix sln
                return "";

            return to_cpp_string( ).c_str( );
        }

        static unity::string* create( const char* value );

        static unity::string* create( std::string value )
        {
            return create( value.c_str( ) );
        }
    };

    template < typename TKey, typename TValue >
    struct [[maybe_unused]] dictionary
    {
        struct entry
        {
            [[maybe_unused]] int hash_code, next;
            TKey key;
            TValue value;
        };

        void* klass;
        void* monitor;
        [[maybe_unused]] array< int >* buckets;
        array< entry >* entries;
        int count;
        int version;
        [[maybe_unused]] int free_list;
        [[maybe_unused]] int free_count;
        [[maybe_unused]] void* comparer;
        array< TKey >* keys;
        array< TValue >* values;
        [[maybe_unused]] void* sync_root;

        std::map< TKey, TValue > to_map( )
        {
            std::map< TKey, TValue > ret;

            for ( auto it = ( entry* ) &entries->m_items; it != ( ( entry* ) &entries->m_items + count ); ++it )
                ret.emplace( std::make_pair( it->key, it->value ) );

            return std::move( ret );
        }

        std::vector< TKey > get_keys( )
        {
            std::vector< TKey > ret;

            for ( int i = 0; i < count; ++i )
                ret.emplace_back( entries->at( i ).key );

            return std::move( ret );
        }

        std::vector< TValue > get_values( )
        {
            std::vector< TValue > ret;

            for ( int i = 0; i < count; ++i )
                ret.emplace_back( entries->at( i ).value );

            return std::move( ret );
        }

        int get_size( )
        {
            return count;
        }

        [[maybe_unused]] int get_version( )
        {
            return version;
        }

        TValue get( TKey key )
        {
            TValue ret;

            if ( TryGet( key, ret ) )
                return ret;

            return { };
        }

        TValue operator[]( TKey key )
        {
            return get( key );
        }
    };

} // namespace unity
