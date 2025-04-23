#pragma once

class c_transform;

class c_component
{
public:
    ~c_component( ) = default;
    c_component( ) = default;

    c_transform* get_transform( ) const;
};