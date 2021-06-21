#pragma once

#include "core/ai_strategies/ai_placement_strategies/ai_placement_strategy/ai_placement_strategy.h"

class AIRandomPlacementStrategy : public AIPlacementStrategy
{
public:
    const IVector2 GetPositionToUse(GameManager& game_manager);
};