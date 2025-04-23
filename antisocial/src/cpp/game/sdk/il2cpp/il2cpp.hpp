#pragma once

#include <dlfcn.h>
#include <cmath>
#include <fstream>
#include <functional>
#include <map>
#include <thread>
#include <unordered_map>
#include <vector>

#include "defines.hpp"
#include "singleton.hpp"

struct il2cpp_functions_t
{
    void* array_new;
    void* class_from_name;
    void* get_corlib;
    void* value_box;
    void* object_unbox;
    void* object_new;
    void* class_get_method_from_name;
    void* field_static_get_value;
    void* field_static_set_value;
    void* class_get_field_from_name;
    void* domain_get;
    void* domain_assembly_open;
    void* assembly_get_image;
    void* domain_get_assemblies;
};

class c_il2cpp_api : public singleton< c_il2cpp_api >
{
public:
    il2cpp_functions_t functions;

public:
    c_il2cpp_api( ) = default;
    ~c_il2cpp_api( ) = default;

    void initialize( );

    il2cpp_image* get_img_to_asm( const char* assembly );
    uintptr_t get_method_pointer( const char* namespaze, const char* clazz, const char* method, int args = 0 );
    il2cpp_class* get_class( const char* namespaze, const char* clazz );
};
