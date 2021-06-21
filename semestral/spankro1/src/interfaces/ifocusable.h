#pragma once

class GameManager;

/**
 * Interface that all classes that handle with user input have to implement
 */
class IFocusable
{
public:
    /**
     * Handles user input
     * 
     * @param key code of key pressed by the user
     * @param game_manager GameManager instance to use
     */
    virtual void HandleInput(const int& key, GameManager& game_manager) = 0;
};