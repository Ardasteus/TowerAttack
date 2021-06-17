#pragma once

#include "ui/window/gui_window.h"
#include "ui/control_creator/control_creator.h"

class MainMenuWindow : public GUIWindow
{
public:
    MainMenuWindow();

    ~MainMenuWindow();

    void Initialize() override;
};