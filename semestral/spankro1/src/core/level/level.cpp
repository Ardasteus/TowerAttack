#include "level.h"

Level::Level(const int& ai_gold, const int& player_gold, const int& p_income, const int& a_income, const int& lives)
{
    starting_ai_gold = ai_gold;
    starting_player_gold = player_gold;
    player_income = p_income;
    ai_income = a_income;
    ai_lives = lives;
}