#include "save_game.h"

bool SaveGame::Load()
{
    fstream save_game;
    save_game.open("./assets/save_game", ios::in);
    if(save_game.is_open())
    {
        string line;
        getline(save_game, line);
        getline(save_game, line);
        vector<int> values = StringUtils::IntSplitStringByDelimiter(line, ";");
        if(values.size() != 4)
        {
            error_message = "Save game failed to load: Wrong amount of arguments. Should be 4.";
            return false;
        }
        current_level = values[0];
        bonus_gold = values[1];
        bonus_income = values[2];
        bonus_hp = values[3];
        return true;
    }
    else
    {
        NewGame();
        return true;
    }
}

void SaveGame::Save()
{
    fstream save_game;
    save_game.open("./assets/save_game_temp", ios::out);
    save_game << "CurrentLevel;BonusGold;BonusIncome;BonusHP" << endl;
    save_game << current_level << ";" << bonus_gold << ";" << bonus_income << ";" << bonus_hp << endl;
    remove("./assets/save_game");
    rename("./assets/save_game_temp", "./assets/save_game");
}

void SaveGame::NewGame()
{
    current_level = 0;
    bonus_gold = 0;
    bonus_income = 0;
    bonus_hp = 0;
    Save();
}

const int& SaveGame::GetLevel() const
{
    return current_level;
}

const int& SaveGame::GetGold() const
{
    return bonus_gold;
}

const int& SaveGame::GetIncome() const
{
    return bonus_income;
}

const int& SaveGame::GetHP() const
{
    return bonus_hp;
}

void SaveGame::SetLevel(const int& value)
{
    current_level = value;
    Save();
}

void SaveGame::SetGold(const int& value)
{
    bonus_gold = value;
    Save();
}

void SaveGame::SetIncome(const int& value)
{
    bonus_income = value;
    Save();
}

void SaveGame::SetHP(const int& value)
{
    bonus_hp = value;
    Save();
}