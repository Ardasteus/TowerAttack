#pragma once

#include "game/game_object/game_object.h"

/**
 * Comparators that sorts GameObject pointers based on the name
 */
struct GameObjectComparator
{
    /**
     * Compare function, sorts based on the name
     * 
     * @param left GameObject to compare
     * @param right GameObject to compare
     * @return Result of the comparison
     */
    bool operator() (const shared_ptr<GameObject> left, const shared_ptr<GameObject> right)
    {
        return left->GetName() < right->GetName();
    }
};