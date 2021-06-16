#pragma once

class GameManager;

class IInitializable
{
public:
    virtual void Initialize(GameManager& game_manager) = 0;
};