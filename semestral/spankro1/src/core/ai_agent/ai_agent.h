#pragma once

#include "interfaces/iupdatable.h"
#include <random>

class AIAgent : public IUpdatable
{
protected:
    int ai_update_time = 50;
    int current_update_time = 0;
    int available_gold = 0;
public:
    void Update(GameManager& game_manager);

    void SetGold(const int& gold);
    void AddGold(const int& income);
};