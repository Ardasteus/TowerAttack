#pragma once

using namespace std;

#include "core/level/level.h"
#include "interfaces/iloadable.h"
#include "utility/string_utilities.h"
#include <string>
#include <vector>
#include <fstream>

class LevelHandler : public ILoadable
{
protected:
    vector<Level> levels;
    int current_level_index = -1;

    int stat_update_timer = 100;
    int current_update_time = 0;
public:
    bool Load() override;
    const string& GetError() const override;

    void GoToNextLevel();
    void GoToSpecificLevel(const int& level);

    const Level& GetCurrentLevel() const;
};