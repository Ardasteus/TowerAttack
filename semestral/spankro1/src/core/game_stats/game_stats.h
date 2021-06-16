#pragma once

using namespace std;

#include "interfaces/iupdatable.h"
#include "core/save_game/save_game.h"
#include"core/level/level.h"
#include <functional>

class GameStats : public IUpdatable
{
protected:
    int player_gold = 0;
    int player_income = 0;
    int lives_left = 0;
    int current_level = 0;
    int ai_gold = 0;
    int ai_income = 0;

    function<void(GameStats&)> on_update_callback;

public:

    void Update(GameManager& game_manager) override;
    const int& GetGold() const;
    const int& GetIncome() const;
    const int& GetLives() const;
    const int& GetLevel() const;
    const int& GetAIGold() const;
    const int& GetAIIncome() const;
    void SetGold(const int& value);
    void SetIncome(const int& value);
    void SetLives(const int& value);
    void SetLevel(const int& value);
    void SetAIGold(const int& value);
    void SetAIIncome(const int& value);
    void SetStats(const Level& level, const SaveGame& save_game);
    void SetOnUpdateCallback(function<void(GameStats&)> func);
    void InvokeOnUpdate();
};