#pragma once

using namespace std;

#include "interfaces/iloadable.h"
#include "utility/string_utilities.h"
#include <fstream>

/**
 * Class encapsuling save game
 */
class SaveGame : public ILoadable
{
protected:
    /**
     * Current level
     */
    int current_level = 0;

    /**
     * Current bonus gold power up
     */
    int bonus_gold = 0;

    /**
     * Current bonus income power up
     */
    int bonus_income = 0;

    /**
     * Current bonus HP power up
     */
    int bonus_hp = 0;
public:
    /**
     * Loads the save game from a file or creates a new one
     * 
     * @return Whether the loading was successful or not
     */
    bool Load() override;

    /**
     * Saves the save game data to a file
     */
    void Save();

    /**
     * Creates a new save game
     */
    void NewGame();

    /**
     * Getter for current level
     */
    const int& GetLevel() const;

    /**
     * Getter for bonus gold
     */
    const int& GetGold() const;

    /**
     * Getter for bonus income
     */
    const int& GetIncome() const;

    /**
     * Getter for bonus HP
     */
    const int& GetHP() const;

    /**
     * Setter for current level. Saves the game when changed
     */
    void SetLevel(const int& value);

    /**
     * Setter for bonus gold. Saves the game when changed
     */
    void SetGold(const int& value);

    /**
     * Setter for bonus income. Saves the game when changed
     */
    void SetIncome(const int& value);

    /**
     * Setter for bonus HP. Saves the game when changed
     */
    void SetHP(const int& value);
};