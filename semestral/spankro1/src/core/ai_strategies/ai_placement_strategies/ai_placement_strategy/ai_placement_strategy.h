#pragma once

#include "math/vector/ivector2.h"

class GameManager;

/**
 * Basee class for all AI placement strategies
 */
class AIPlacementStrategy
{
public:

    /**
     * Returns the position to spawn the DefenderEntity on
     * 
     * @param game_manager GameManager instance to use
     * 
     * @return Position to use
     */
    virtual const IVector2 GetPositionToUse(GameManager& game_manager) = 0;
};