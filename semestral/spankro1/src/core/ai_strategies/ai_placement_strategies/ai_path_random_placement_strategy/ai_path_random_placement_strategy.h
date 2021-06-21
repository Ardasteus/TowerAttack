#pragma once

#include "core/ai_strategies/ai_placement_strategies/ai_placement_strategy/ai_placement_strategy.h"

/**
 * Strategy to place a DefenderEntity on a random tile close to a path
 */
class AIPathRandomPlacementStrategy : public AIPlacementStrategy
{
public:

    /**
     * Returns the position to spawn the DefenderEntity on
     * 
     * @param game_manager GameManager instance to use
     * 
     * @return Position to use
     */
    const IVector2 GetPositionToUse(GameManager& game_manager);
};