#include "ai_path_random_placement_strategy.h"
#include "core/game_manager/game_manager.h"

const IVector2 AIPathRandomPlacementStrategy::GetPositionToUse(GameManager& game_manager)
{
    random_device rand;
    mt19937 rng(rand());
    vector<shared_ptr<GameObject>> paths = game_manager.GetAllPaths();
    uniform_int_distribution<int> rand_path(0, paths.size() - 1);
    uniform_int_distribution<int> rand_x(-4, 4);
    uniform_int_distribution<int> rand_y(-4, 4);

    auto index = paths.begin();
    advance(index, rand_path(rng));
    IVector2 random_offset(rand_x(rng), rand_y(rng));

    return index->get()->GetPosition() + random_offset;
}