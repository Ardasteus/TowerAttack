#pragma once

class GameManager;

/**
 * Interface that every service that runs while the game is on, has to implement.
 */
class IUpdatable
{
public:
    /**
     * Updates the object
     * 
     * @param game_manager GameManager instance to use
     */
    virtual void Update(GameManager& game_manager) = 0;
};