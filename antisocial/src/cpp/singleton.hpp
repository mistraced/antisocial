#pragma once

#include <memory>
#include <mutex>

template < typename T >
class singleton
{
public:
    singleton( const singleton& ) = delete;
    singleton& operator=( const singleton& ) = delete;

    static std::unique_ptr< T >& get_instance( )
    {
        static std::once_flag flag;
        std::call_once( flag, []( ) {
            instance.reset( new T( ) );
        } );
        return instance;
    }

    static T* get( )
    {
        static std::once_flag flag;
        std::call_once( flag, []( ) {
            instance.reset( new T( ) );
        } );
        return instance.get( );
    }

protected:
    singleton( ) = default;
    virtual ~singleton( ) = default;

private:
    static inline std::unique_ptr< T > instance;
};
