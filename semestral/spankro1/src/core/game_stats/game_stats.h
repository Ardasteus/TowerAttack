#pragma once

using namespace std;

#include "core/level/level.h"
#include "utility/string_utilities.h"
#include <vector>
#include <functional>
#include <fstream>

class GameStats
{
private:
    vector<Level> levels;
    function<void()> onStatsUpdate;
public:
    int current_level;
    int player_income;
    int ai_income;
    int player_gold;
    int ai_gold;
    int lives;
    int ai_update_time;

    GameStats();
    void LoadLevels();
    void NextLevel();
    void SetUpdateFunction(function<void()> func);
    void InvokeUpdate();
private:
    void SetValues();
};