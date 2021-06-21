#pragma once

class GameManager;

/**
 * Interface that all services that initialize have to implement.
 */
class IInitializable
{
public:

    /**
     * Initializes the object, for example creates buttons in windows.
     * 
     * @param game_manager GameManager instance to use
     */
    virtual void Initialize(GameManager& game_manager) = 0;
};