#pragma once

using namespace std;

#include "interfaces/iupdatable.h"
#include "core/save_game/save_game.h"
#include"core/level/level.h"
#include "interfaces/iinitializable.h"
#include <functional>

/**
 * Class encapsulating current game stats
 */
class GameStats : public IUpdatable, public IInitializable
{
protected:
    /**
     * Current player gold
     */
    int player_gold;

    /**
     * Current player income
     */
    int player_income;

    /**
     * Current lives left
     */
    int lives_left;

    /**
     * Current level
     */
    int current_level;

    /**
     * Current AI gold
     */
    int ai_gold;

    /**
     * Current AI income
     */
    int ai_income;

    /**
     * Update callback
     */
    function<void(GameStats&)> on_update_callback;

    /**
     * On lives loft callback
     */
    function<void(GameManager&)> on_lives_lost_callback;

    /**
     * Update timer threshold
     */
    int update_timer = 100;

    /**
     * Current update timer
     */
    int current_update_timer = 0;

public:
    /**
     * Updates the stats
     * 
     * @param game_manager GameManager instance to use
     */
    void Update(GameManager& game_manager) override;

    /**
     * Initializes the event handles used
     * 
     * @param game_manager GameManager instance to use
     */
    void Initialize(GameManager& game_manager) override;

    /**
     * Getter for current gold
     */
    const int& GetGold() const;

    /**
     * Getter for current income
     */
    const int& GetIncome() const;

    /**
     * Getter for current lives
     */
    const int& GetLives() const;

    /**
     * Getter for current level
     */
    const int& GetLevel() const;

    /**
     * Getter for current ai gold
     */
    const int& GetAIGold() const;

    /**
     * Getter for current ai income
     */
    const int& GetAIIncome() const;

    /**
     * Setter for current gold
     * 
     * @param value Value to set to
     */
    void SetGold(const int& value);

    /**
     * Setter for current income
     * 
     * @param value Value to set to
     */
    void SetIncome(const int& value);

    /**
     * Setter for current lives
     * 
     * @param value Value to set to
     */
    void SetLives(const int& value);

    /**
     * Decrements current lives amount
     */
    void DecrementLives();

    /**
     * Setter for current level
     * 
     * @param value Value to set to
     */
    void SetLevel(const int& value);

    /**
     * Setter for current ai gold
     * 
     * @param value Value to set to
     */
    void SetAIGold(const int& value);

    /**
     * Setter for current ai income
     * 
     * @param value Value to set to
     */
    void SetAIIncome(const int& value);
    
    /**
     * Sets the game stats from given Level and SaveGame instances
     * 
     * @param level Level to use
     * @param save_game SaveGame to use
     */
    void SetStats(const Level& level, const SaveGame& save_game);

    /**
     * Sets function to be called when stats get updated
     * 
     * @param func Function to use
     */
    void SetOnUpdateCallback(function<void(GameStats&)> func);

    /**
     * Sets function to be called when lives get to 0
     * 
     * @param func Function to use
     */
    void SetOnLivesLostCallback(function<void(GameManager&)> func);

    /**
     * Invokes the on update method
     */
    void InvokeOnUpdate();

    /**
     * Invokes the on lives lost method
     */
    void InvokeOnLivesLost(GameManager& game_manager);
};