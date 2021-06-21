#pragma once

using namespace std;

#include "core/ai_strategies/ai_choice_strategies/ai_choice_strategy/ai_choice_strategy.h"
#include <vector>
#include <random>

/**
 * Strategy to select a random DefenderTemplate that has the "Furthest" AttackType
 */
class AIFurthestStrategy : public AIChoiceStrategy
{
public:

    /**
     * Selects a random Furthest Attack type DefenderTemplate and returns it
     * 
     * @param game_manager GameManager instance to be used
     * 
     * @return DefenderTemplate to be used
     */
    const DefenderTemplate GetTemplateToUse(GameManager& game_manager) override;
};