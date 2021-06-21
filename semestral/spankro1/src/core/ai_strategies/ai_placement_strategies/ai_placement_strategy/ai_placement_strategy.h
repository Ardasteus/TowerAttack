#pragma once

#include "math/vector/ivector2.h"

class GameManager;

class AIPlacementStrategy
{
public:
    virtual const IVector2 GetPositionToUse(GameManager& game_manager) = 0;
};