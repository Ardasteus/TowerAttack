#include "level.h"

Level::Level(int ai_gold, int player_gold, int p_income, int a_income, int lives)
{
    starting_ai_gold = ai_gold;
    starting_player_gold = player_gold;
    player_income = p_income;
    ai_income = a_income;
    ai_lives = lives;
}