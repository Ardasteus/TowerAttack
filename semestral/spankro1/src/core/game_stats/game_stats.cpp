#include "game_stats.h"
#include "core/game_manager/game_manager.h"

void GameStats::Update(GameManager& game_manager)
{
    if(lives_left <= 0)
    {
        InvokeOnLivesLost(game_manager);
        return;
    }

    current_update_timer++;
    if(current_update_timer != update_timer)
        return;

    current_update_timer = 0;
    SetGold(player_gold + player_income);
}

void GameStats::Initialize(GameManager&)
{
    SetOnLivesLostCallback([&](GameManager& game_manager)
    {
        game_manager.GoToNextLevel();
    });
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

void GameStats::DecrementLives()
{
    lives_left--;
    InvokeOnUpdate();
}

void GameStats::SetStats(const Level& level, const SaveGame& save_game)
{
    player_gold = level.starting_player_gold + save_game.GetGold();
    player_income = level.player_income + save_game.GetIncome();
    ai_gold = level.starting_ai_gold;
    ai_income = level.ai_income;
    lives_left = level.ai_lives;
    current_level = save_game.GetLevel();
    InvokeOnUpdate();
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

void GameStats::SetOnLivesLostCallback(function<void(GameManager&)> func)
{
    on_lives_lost_callback = func;
}

void GameStats::InvokeOnLivesLost(GameManager& game_manager)
{
    if(on_lives_lost_callback != nullptr)
        on_lives_lost_callback(game_manager);
}