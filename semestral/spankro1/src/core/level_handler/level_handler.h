#pragma once

using namespace std;

#include "core/level/level.h"
#include "interfaces/iloadable.h"
#include "utility/string_utilities.h"
#include <string>
#include <vector>
#include <fstream>

/**
 * Handles the loading of available levels
 */
class LevelHandler : public ILoadable
{
protected:
    /**
     * Vector of available levels
     */
    vector<Level> levels;

    /**
     * Index of current level
     */
    int current_level_index = -1;

    /**
     * Update time threshold
     */
    int stat_update_timer = 100;

    /**
     * Current update timer
     */
    int current_update_time = 0;
public:
    /**
     * Loads available levels from a file
     * 
     * @return true if everything loaded correctly
     */
    bool Load() override;

    /**
     * Moves the index to next level
     */
    void GoToNextLevel();

    /**
     * Sets the current level to given level
     * 
     * @param level Level to go to
     */
    void GoToSpecificLevel(const int& level);

    /**
     * Gets the current level
     * 
     * @return reference to current level
     */
    const Level& GetCurrentLevel() const;

    /**
     * Returns index of current level
     * 
     * @return index of current level
     */
    const int& GetCurrentLevelId() const;
};