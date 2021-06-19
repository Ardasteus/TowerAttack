#pragma once

using namespace std;

#include "core/ai_strategies/ai_choice_strategies/ai_choice_strategy/ai_choice_strategy.h"
#include <vector>
#include <random>

class AIClosestStrategy : public AIChoiceStrategy
{
public:
    const DefenderTemplate GetTemplateToUse(GameManager& game_manager) override;
};