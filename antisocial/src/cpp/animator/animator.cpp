#include "animator.hpp"

#include "imgui.h"
#include "imgui_internal.h"

float smooth_ease( float time, float start_value, float change_value, float duration )
{
    time = time / duration - 1.f;
    float easing = ( time * time * time + 1.f );

    return change_value * easing * 0.45f + start_value;
}

float resolve_value( float clock, float previous_value, float new_value, float duration )
{
    float value = smooth_ease( clock, previous_value, new_value - previous_value, duration );

    if ( std::abs( value - new_value ) < 0.001f )
    {
        value = new_value;
    }

    return value;
}

void animation::update( float to_value, float duration )
{
    if ( this->value == to_value )
        return;

    float delta_time = ImGui::GetIO( ).DeltaTime;
    this->value = resolve_value( delta_time, this->value, to_value, duration );
}