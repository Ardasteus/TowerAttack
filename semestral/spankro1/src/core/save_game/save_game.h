#pragma once

#include "utility/string_utilities.h"
#include <fstream>

class SaveGame
{
public:
    int current_level;
    int bonus_gold;
    int bonus_income;
    int bonus_hp;

    SaveGame();
    
    bool Load();
    bool Save();
};