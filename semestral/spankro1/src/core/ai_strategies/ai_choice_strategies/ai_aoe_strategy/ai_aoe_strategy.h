#pragma once

using namespace std;

#include "core/ai_strategies/ai_choice_strategies/ai_choice_strategy/ai_choice_strategy.h"
#include <vector>
#include <random>

/**
 * Strategy that selects a random AoE only DefenderTemplate to spawn
 */
class AIAoeStrategy : public AIChoiceStrategy
{
public:

    /**
     * Selects a random AoE Defender Template and returns it
     * 
     * @param game_manager GameManager instance to be used
     * 
     * @return DefenderTemplate to be used
     */
    const DefenderTemplate GetTemplateToUse(GameManager& game_manager) override;
};