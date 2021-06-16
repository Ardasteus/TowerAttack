#include "level_handler.h"

bool LevelHandler::Load()
{
    levels.clear();
    fstream levels_file;
    levels_file.open("./assets/levels", ios::in);
    if(levels_file.is_open())
    {
        string line;
        getline(levels_file, line);
        while (getline(levels_file, line))
        {
            vector<int> values = StringUtils::IntSplitStringByDelimiter(line, ";");
            if(values.size() != 5)
            {
                levels_file.close();
                error_message = "Levels could not be loaded: Wrong amount of parameters. Should be 5.";
                return false;
            }
            Level new_level(values[0], values[1], values[3], values[2], values[4]);
            levels.push_back(new_level);
        }
        levels_file.close();
        error_message = "";
        return true;
    }
    else
    {
        error_message = "Levels could not be loaded: file (./assets/levels) could not be opened.";
        return false;
    }

}

void LevelHandler::GoToNextLevel()
{
    int actual_level = current_level_index + 1;
    if(actual_level < 0 || actual_level >= (int)levels.size())
        actual_level = 0;

    current_level_index = actual_level;
}

void LevelHandler::GoToSpecificLevel(const int& level)
{
    int actual_level = level;
    if(level < 0 || level >= (int)levels.size())
        actual_level = 0;

    current_level_index = actual_level;
}

const string& LevelHandler::GetError() const
{
    return error_message;
}

const Level& LevelHandler::GetCurrentLevel() const
{
    return levels[current_level_index];
}