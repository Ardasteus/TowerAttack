#pragma once

using namespace std;

#include "core/ai_strategies/ai_choice_strategies/ai_choice_strategy/ai_choice_strategy.h"
#include <map>
#include <random>

/**
 * Strategy that cycles between types of DefenderTemplates to be used
 */
class AICyclicStrategy : public AIChoiceStrategy
{
protected:
    /**
     * Current AttackType
     */
    AttackType current_type = AttackType::Closest;
public:

    /**
     * Selects a random DefenderTemplate of the current type and cycles to the next type
     * 
     * @param game_manager GameManager instance to be used
     * 
     * @return DefenderTemplate to be used
     */
    const DefenderTemplate GetTemplateToUse(GameManager& game_manager) override;
};