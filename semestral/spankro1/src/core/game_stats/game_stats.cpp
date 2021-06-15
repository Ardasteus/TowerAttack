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

void GameStats::SetSpecificLevel(const int& level, SaveGame& save_game)
{
    int actual_level = level;
    if(level < 0 || level >= (int)levels.size())
        actual_level = 0;

    save_game.current_level = actual_level;
    current_level = actual_level;
    SetValues(save_game);
}

bool GameStats::LoadLevels(string& error_message)
{
    fstream level_definitions;
    level_definitions.open("./assets/levels", ios::in);
    if(level_definitions.is_open())
    {
        string line;
        getline(level_definitions, line);
        while(getline(level_definitions, line))
        {
            vector<int> values = StringUtils::IntSplitStringByDelimiter(line, ";");
            if(values.size() != 5)
            {
                level_definitions.close();
                error_message = "Levels could not be loaded: Wrong amount of parameters. Should be 5";
                return false;
            }
            Level new_level = Level(values[0], values[1], values[3], values[2], values[4]);
            levels.push_back(new_level);
        }
        level_definitions.close();
        return true;
    }
    else
    {
        error_message = "Levels could not be loaded: File (./assets/levels) could not be opened.";
        return false;
    }
}

void GameStats::SetUpdateFunction(const function<void()>& func)
{
    on_stats_update = func;
}

void GameStats::InvokeUpdate()
{
    on_stats_update();
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
    on_stats_update();
}