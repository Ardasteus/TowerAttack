#pragma once

/**
 * Interface that all classes that handle with user input have to implement
 */
class GameManager;

class IFocusable
{
public:

    virtual void HandleInput(const int& key, GameManager& game_manager) = 0;
};