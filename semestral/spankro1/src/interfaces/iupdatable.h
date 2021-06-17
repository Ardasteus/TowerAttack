#pragma once

class GameManager;

class IUpdatable
{
public:
    virtual void Update(GameManager& game_manager) = 0;
};