#pragma once

using namespace std;

#include "interfaces/iupdatable.h"
#include "core/save_game/save_game.h"
#include"core/level/level.h"
#include "interfaces/iinitializable.h"
#include <functional>

class GameStats : public IUpdatable, public IInitializable
{
protected:
    int player_gold = 500;
    int player_income = 0;
    int lives_left = 0;
    int current_level = 0;
    int ai_gold = 500;
    int ai_income = 0;

    function<void(GameStats&)> on_update_callback;
    function<void(GameManager&)> on_lives_lost_callback;

    int update_timer = 100;
    int current_update_timer = 0;

public:

    void Update(GameManager& game_manager) override;
    void Initialize(GameManager& game_manager) override;
    const int& GetGold() const;
    const int& GetIncome() const;
    const int& GetLives() const;
    const int& GetLevel() const;
    const int& GetAIGold() const;
    const int& GetAIIncome() const;
    void SetGold(const int& value);
    void SetIncome(const int& value);
    void SetLives(const int& value);
    void DecrementLives();
    void SetLevel(const int& value);
    void SetAIGold(const int& value);
    void SetAIIncome(const int& value);
    void SetStats(const Level& level, const SaveGame& save_game);
    void SetOnUpdateCallback(function<void(GameStats&)> func);
    void SetOnLivesLostCallback(function<void(GameManager&)> func);
    void InvokeOnUpdate();
    void InvokeOnLivesLost(GameManager& game_manager);
};