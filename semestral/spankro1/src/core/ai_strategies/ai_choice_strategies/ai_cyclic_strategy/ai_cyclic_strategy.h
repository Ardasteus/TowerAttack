#pragma once

using namespace std;

#include "core/ai_strategies/ai_choice_strategies/ai_choice_strategy/ai_choice_strategy.h"
#include <map>
#include <random>

class AICyclicStrategy : public AIChoiceStrategy
{
protected:
    AttackType current_type = AttackType::Closest;
public:
    const DefenderTemplate GetTemplateToUse(GameManager& game_manager) override;
};