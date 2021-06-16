#include "game_stats.h"

void GameStats::Update(GameManager& game_manager)
{

}

const int& GameStats::GetGold() const
{
    return player_gold;
}

const int& GameStats::GetIncome() const
{
    return player_income;
}

const int& GameStats::GetLives() const
{
    return lives_left;
}

const int& GameStats::GetLevel() const
{
    return current_level;
}

const int& GameStats::GetAIGold() const
{
    return ai_gold;
}

const int& GameStats::GetAIIncome() const
{
    return ai_income;
}

void GameStats::SetGold(const int& value)
{
    player_gold = value;
    InvokeOnUpdate();
}

void GameStats::SetIncome(const int& value)
{
    player_income = value;
    InvokeOnUpdate();
}

void GameStats::SetLives(const int& value)
{
    lives_left = value;
    InvokeOnUpdate();
}

void GameStats::SetLevel(const int& value)
{
    current_level = value;
    InvokeOnUpdate();
}

void GameStats::SetAIGold(const int& value)
{
    ai_gold = value;
    InvokeOnUpdate();
}

void GameStats::SetAIIncome(const int& value)
{
    ai_income = value;
    InvokeOnUpdate();
}

void GameStats::SetStats(const Level& level, const SaveGame& save_game)
{
    player_gold = level.starting_player_gold + save_game.GetGold();
    player_income = level.player_income + save_game.GetIncome();
    ai_gold = level.starting_ai_gold;
    ai_income = level.ai_income;
    current_level = save_game.GetLevel();
}

void GameStats::SetOnUpdateCallback(function<void(GameStats&)> func)
{
    on_update_callback = func;
}

void GameStats::InvokeOnUpdate()
{
    if(on_update_callback != nullptr)
        on_update_callback(*this);
}