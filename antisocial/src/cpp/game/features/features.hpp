#pragma once

#include "singleton.hpp"

class c_player_controller;

class c_features_manager : public singleton< c_features_manager >
{
public:
    void process_local_player( c_player_controller* local ) const;
};