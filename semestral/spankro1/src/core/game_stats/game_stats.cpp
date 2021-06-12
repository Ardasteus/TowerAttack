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

void GameStats::NextLevel(SaveGame& save_game)
{
    save_game.current_level = ++current_level;
    if(current_level == (int)levels.size())
        current_level = 0;

    SetValues(save_game);
}

void GameStats::SetSpecificLevel(int level, SaveGame& save_game)
{
    if(level < 0 || level >= (int)levels.size())
        level = 0;

    save_game.current_level = level;
    current_level = level;
    SetValues(save_game);
}

void GameStats::LoadLevels()
{
    fstream level_definitions;
    level_definitions.open("./src/data/levels", ios::in);
    if(level_definitions.is_open())
    {
        string line;
        getline(level_definitions, line);
        while(getline(level_definitions, line))
        {
            vector<int> values = StringUtils::IntSplitStringByDelimiter(line, ";");
            Level new_level = Level(values[0], values[1], values[3], values[2], values[4]);
            levels.push_back(new_level);
        }
        level_definitions.close();
    }
}

void GameStats::SetUpdateFunction(function<void()> func)
{
    onStatsUpdate = func;
}

void GameStats::InvokeUpdate()
{
    onStatsUpdate();
}

void GameStats::SetValues(SaveGame& save_game)
{
    if(current_level < 0 || current_level >= (int)levels.size())
        return;

    Level level = levels[current_level];
    player_income = level.player_income + save_game.bonus_income;
    ai_income = level.ai_income;
    player_gold = level.starting_player_gold + save_game.bonus_gold;
    ai_gold = level.starting_ai_gold;
    lives = level.ai_lives;
    onStatsUpdate();
}