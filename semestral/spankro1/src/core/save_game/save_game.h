#pragma once

#include "utility/string_utilities.h"
#include <fstream>

/**
 * Class that stores all save game information.
 * 
 * Currently only one save game
 */
class SaveGame
{
public:
    /**
     * Current level that the player is on
     */
    int current_level;

    /**
     * How much bonus gold is the player getting on the start of a level
     */
    int bonus_gold;

    /**
     * How much bonus income is the player getting
     */
    int bonus_income;

    /**
     * Increases the HP of AttackerEntity objects spawned by the player
     */
    int bonus_hp;

    /**
     * Default constructor
     */
    SaveGame();
    
    /**
     * Loads the save game from file
     */
    bool Load();

    /**
     * Saves the save game to file
     */
    bool Save();
};