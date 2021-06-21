#pragma once

#include "interfaces/iupdatable.h"
#include "interfaces/iloadable.h"
#include "utility/string_utilities.h"
#include "core/ai_strategies/ai_choice_strategies/ai_choice_strategy/ai_choice_strategy.h"
#include "core/ai_strategies/ai_choice_strategies/ai_aoe_strategy/ai_aoe_strategy.h"
#include "core/ai_strategies/ai_choice_strategies/ai_closest_strategy/ai_closest_strategy.h"
#include "core/ai_strategies/ai_choice_strategies/ai_cyclic_strategy/ai_cyclic_strategy.h"
#include "core/ai_strategies/ai_choice_strategies/ai_furthest_strategy/ai_furthest_strategy.h"
#include "core/ai_strategies/ai_placement_strategies/ai_placement_strategy/ai_placement_strategy.h"
#include "core/ai_strategies/ai_placement_strategies/ai_random_placement_strategy/ai_random_placement_strategy.h"
#include "core/ai_strategies/ai_placement_strategies/ai_path_random_placement_strategy/ai_path_random_placement_strategy.h"
#include "core/ai_strategies/ai_choice_strategies/ai_random_strategy/ai_random_strategy.h"
#include <random>
#include <memory>

/**
 * The AI responsible for placing defenders in the game. Has multiple strategies for both placement and choosing types of defenders.
 */
class AIAgent : public IUpdatable, public ILoadable
{
protected:
    /**
     * The update threshold when the agent is supposed to update
     */
    int ai_update_time;

    /**
     * Current update timer
     */
    int current_update_time = 0;

    /**
     * Strategy that determines which defender is spawned.
     */
    unique_ptr<AIChoiceStrategy> defender_choice_strategy;

    /**
     * Strategy that determines where the defender is placed.
     */
    unique_ptr<AIPlacementStrategy> placement_strategy;
public:
    /**
     * Runs the update of the AI. If current_update_time hits the threshold the AIAgent tries to spawn a defender.
     * 
     * @param game_manager GameManager instance to use
     */
    void Update(GameManager& game_manager);

    /**
     * Loads required data from file
     * 
     * @return Whether or not data loaded
     */
    bool Load() override;

    /**
     * Resets the update clock back to 0
     */
    void ResetTimer();
};