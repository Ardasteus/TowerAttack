#pragma once

using namespace std;

#include "core/level/level.h"
#include <vector>
#include <functional>

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

    GameStats();
    void LoadLevels();
    void SetLevel(int level);
    void SetUpdateFunction(function<void()> func);
    void InvokeUpdate();
};