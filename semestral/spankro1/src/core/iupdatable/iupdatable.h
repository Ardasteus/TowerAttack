#pragma once

class GameManager;

class IUpdatable
{
public:
    virtual void Update(const GameManager& game_manager, const int& current_tick);
};