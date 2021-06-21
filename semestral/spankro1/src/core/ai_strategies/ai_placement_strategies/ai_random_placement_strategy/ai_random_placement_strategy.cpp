#include "ai_random_placement_strategy.h"
#include "core/game_manager/game_manager.h"

const IVector2 AIRandomPlacementStrategy::GetPositionToUse(GameManager&)
{
    random_device rand;
    mt19937 rng(rand());
    uniform_int_distribution<int> rand_x(0, GAME_WIDTH - 1);
    uniform_int_distribution<int> rand_y(0, GAME_HEIGHT - 1);
    return IVector2(rand_x(rng), rand_y(rng));
}