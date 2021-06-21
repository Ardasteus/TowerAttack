#pragma once

#include "ui/window/gui_window.h"
#include "ui/control_creator/control_creator.h"

/**
 * Class representing the window where player chooses power ups after beating a level
 */
class LevelFinishedWindow : public GUIWindow
{
public:
    /**
     * Default constructor, initializing the underlying GUIWindow
     */
    LevelFinishedWindow();

    /**
     * Initialization function creating all the buttons etc.
     */
    void Initialize() override;
};