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