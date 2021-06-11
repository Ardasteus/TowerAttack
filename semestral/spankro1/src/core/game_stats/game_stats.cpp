#include "game_stats.h"

GameStats::GameStats()
{
    current_level = -1;
    player_income = 0;
    ai_income = 0;
    player_gold = 0;
    ai_gold = 0;
    lives = 0;
}

void GameStats::SetLevel(int level)
{
    if(level < 0 || level >= levels.size())
        return;

    current_level = level;
    Level new_level = levels[level];
    player_income = new_level.player_income;
    ai_income = new_level.ai_income;
    player_gold = new_level.starting_player_gold;
    ai_gold = new_level.starting_ai_gold;
    lives = new_level.ai_lives;
    onStatsUpdate();
}

void GameStats::LoadLevels()
{
    Level test_level = Level(50, 50, 10, 10, 10);
    levels.push_back(test_level);
}

void GameStats::SetUpdateFunction(function<void()> func)
{
    onStatsUpdate = func;
}

void GameStats::InvokeUpdate()
{
    onStatsUpdate();
}