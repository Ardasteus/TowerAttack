#pragma once

using namespace std;

#include "core/game_stats/game_stats.h"
#include "ui/window/gui_window.h"
#include "ui/controls/label/label.h"
#include "ui/control_creator/control_creator.h"
#include <map>

class GameStatsWindowHandler
{
private:
    GUIWindow window;
    map<string, shared_ptr<Label>> labels;
public:
    GameStatsWindowHandler();
    GameStatsWindowHandler(const int& width, const int& height, const IVector2& position);

    void Initialize();
    void UpdateWindow(const GameStats& stats);
    void Draw(const Drawer& drawer) const;
};
