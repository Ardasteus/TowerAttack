#include "save_game.h"

SaveGame::SaveGame()
{
    current_level = 0;
    bonus_gold = 0;
    bonus_income = 0;
    bonus_hp = 0;
}

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
        current_level = values[0];
        bonus_gold = values[1];
        bonus_income = values[2];
        bonus_hp = values[3];
    }
    else
    {
        Save();
    }
    return true;
}

bool SaveGame::Save()
{
    fstream save_game;
    save_game.open("./assets/save_game_temp", ios::out);
    save_game << "CurrentLevel;BonusGold;BonusIncome;BonusHP" << endl;
    save_game << current_level << ";" << bonus_gold << ";" << bonus_income << ";" << bonus_hp << endl;
    remove("./assets/save_game");
    rename("./assets/save_game_temp", "./assets/save_game");
    return true;
}