#pragma once

#include "ui/window/gui_window.h"
#include "ui/control_creator/control_creator.h"

/**
 * Class representing the main menu of the game.
 */
class MainMenuWindow : public GUIWindow
{
public:
    /**
     * Default constructor, initializing the underlying GUIWindow
     */
    MainMenuWindow();

    /**
     * Initialization function creating all the buttons etc.
     */
    void Initialize() override;
};