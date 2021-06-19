#pragma once

#include "interfaces/iupdatable.h"
#include "interfaces/iloadable.h"
#include "utility/string_utilities.h"
#include "core/ai_strategies/ai_choice_strategies/ai_choice_strategy/ai_choice_strategy.h"
#include "core/ai_strategies/ai_choice_strategies/ai_aoe_strategy/ai_aoe_strategy.h"
#include "core/ai_strategies/ai_choice_strategies/ai_closest_strategy/ai_closest_strategy.h"
#include "core/ai_strategies/ai_choice_strategies/ai_cyclic_strategy/ai_cyclic_strategy.h"
#include "core/ai_strategies/ai_choice_strategies/ai_furthest_strategy/ai_furthest_strategy.h"
#include <random>
#include <memory>

class AIAgent : public IUpdatable, public ILoadable
{
protected:
    int ai_update_time = 250;
    int current_update_time = 0;
    unique_ptr<AIChoiceStrategy> defender_choice_strategy;
public:
    void Update(GameManager& game_manager);
    bool Load() override;

    void ResetTimer();
};