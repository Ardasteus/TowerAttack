#pragma once

using namespace std;

#include "interfaces/iloadable.h"
#include "utility/string_utilities.h"
#include <fstream>

class SaveGame : public ILoadable
{
protected:
    string error_message = "";
    int current_level = 0;
    int bonus_gold = 0;
    int bonus_income = 0;
    int bonus_hp = 0;
public:
    bool Load() override;
    const string& GetError() const override;

    void Save();
    void NewGame();

    const int& GetLevel() const;
    const int& GetGold() const;
    const int& GetIncome() const;
    const int& GetHP() const;

    void SetLevel(const int& value);
    void SetGold(const int& value);
    void SetIncome(const int& value);
    void SetHP(const int& value);
};