#pragma once

using namespace std;

#include "interfaces/iupdatable.h"

class GameStats : public IUpdatable
{
protected:
    int player_gold = 0;
    int player_income = 0;
    int lives_left = 0;
    int current_level = 0;

public:

    void Update(GameManager& game_manager) override;
    const int& GetGold() const;
    const int& GetIncome() const;
    const int& GetLives() const;
    const int& GetLevel() const;

};