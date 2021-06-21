#pragma once

#include "ui/window/gui_window.h"
#include "ui/control_creator/control_creator.h"

class LevelFinishedWindow : public GUIWindow
{
public:
    LevelFinishedWindow();

    void Initialize() override;
};