#pragma once

using namespace std;

#include "core/level/level.h"
#include "utility/string_utilities.h"
#include "core/save_game/save_game.h"
#include <vector>
#include <functional>
#include <fstream>

/**
 * Stores current game stats
 */
class GameStats
{
protected:
    /**
     * Vector of available levels
     */
    vector<Level> levels;

    /**
     * Callback to be called when stats are updated
     */
    function<void()> on_stats_update;
public:
    /**
     * Current level
     */
    int current_level;

    /**
     * Current income of the player
     */
    int player_income;

    /**
     * Current income when AI kills an AttackerEntity
     */
    int ai_income;

    /**
     * Current player gold
     */
    int player_gold;

    /**
     * Current AI gold
     */
    int ai_gold;

    /**
     * Lives left
     */
    int lives;

    /**
     * Default constructor
     */
    GameStats();

    /**
     * Loads available levels from a file
     */
    void LoadLevels();

    /**
     * Goes to the next level and updates given SaveGame instance
     * 
     * @param save_game SaveGame to update
     */
    void NextLevel(SaveGame& save_game);

    /**
     * Goes to specific level and updates given SaveGame instance. If that level is not available, goes to 0
     * 
     * @param level Level to go to
     * @param save_game SaveGame to update
     */
    void SetSpecificLevel(int level, SaveGame& save_game);

    /**
     * Sets on_stats_update function
     * 
     * @param func Function to be used
     */
    void SetUpdateFunction(function<void()> func);

    /**
     * Invokes the on_stats_update callback
     */
    void InvokeUpdate();
protected:

    /**
     * Updates the GameStats instance taking values from current level and global save game bonuses
     */
    void SetValues(SaveGame& save_game);
};