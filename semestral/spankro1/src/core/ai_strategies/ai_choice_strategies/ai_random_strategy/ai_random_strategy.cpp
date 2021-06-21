#include "ai_random_strategy.h"
#include "core/game_manager/game_manager.h"

using namespace std;

const DefenderTemplate AIRandomStrategy::GetTemplateToUse(GameManager& game_manager)
{
    return game_manager.GetRandomDefenderTemplate();;
}