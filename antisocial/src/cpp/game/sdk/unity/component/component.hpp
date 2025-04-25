#pragma once

namespace unity
{
    struct string;
};

class c_transform;

class c_component
{
public:
    ~c_component( ) = default;
    c_component( ) = default;

    c_transform* get_transform( ) const;
    unity::string* get_tag( ) const;
};