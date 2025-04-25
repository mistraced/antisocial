#pragma once

#include <vector>

class c_transform;

class c_biped_map
{
public:
    c_transform* head( ) const;
    c_transform* neck( ) const;
    c_transform* spine1( ) const;
    c_transform* spine2( ) const;
    c_transform* left_shoulder( ) const;
    c_transform* left_upperarm( ) const;
    c_transform* left_forearm( ) const;
    c_transform* left_hand( ) const;
    c_transform* right_shoulder( ) const;
    c_transform* right_upperarm( ) const;
    c_transform* right_forearm( ) const;
    c_transform* right_hand( ) const;
    c_transform* hip( ) const;
    c_transform* left_thigh( ) const;
    c_transform* left_calf( ) const;
    c_transform* left_foot( ) const;
    c_transform* right_thigh( ) const;
    c_transform* right_calf( ) const;
    c_transform* right_foot( ) const;
    c_transform* right_thumb0( ) const;
    c_transform* left_thumb0( ) const;
    c_transform* r_finger0( ) const;
    c_transform* r_finger1( ) const;
    c_transform* r_finger2( ) const;
    c_transform* r_finger3( ) const;
    c_transform* r_finger4( ) const;

    void get_customized( std::vector< c_transform* >& result, bool include_head, bool include_body, bool include_arms, bool include_legs ) const;
    std::vector< c_transform* > get_all( ) const;
    std::vector< c_transform* > get_cut( ) const;
};