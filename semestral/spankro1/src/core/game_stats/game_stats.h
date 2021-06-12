#pragma once

using namespace std;

#include "core/level/level.h"
#include "utility/string_utilities.h"
#include "core/save_game/save_game.h"
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
    void NextLevel(SaveGame& save_game);
    void SetSpecificLevel(int level, SaveGame& save_game);
    void SetUpdateFunction(function<void()> func);
    void InvokeUpdate();
private:
    void SetValues(SaveGame& save_game);
};