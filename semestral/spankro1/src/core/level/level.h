#pragma once

class Level
{
public:
    int starting_ai_gold;
    int starting_player_gold;
    int player_income;
    int ai_income;
    int ai_lives;

    Level(int ai_gold, int player_gold, int p_income, int a_income, int lives);
};