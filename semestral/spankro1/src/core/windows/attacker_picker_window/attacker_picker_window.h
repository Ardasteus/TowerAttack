#pragma once

using namespace std;

#include "ui/window/gui_window.h"
#include "ui/control_creator/control_creator.h"
#include "interfaces/iinitializable.h"

/**
 * Window that enables the player to spawn attackers
 */
class AttackerPickerWindow : public GUIWindow, public IInitializable
{
public:

    using BaseWindow::Initialize;

    /**
     * Constructor that creates a window of given width and height at given position
     * 
     * @param width Width of the window
     * @param height Height of the window
     * @param position Position of the window
     */
    AttackerPickerWindow(const int& width, const int& height, const IVector2& position);

    /**
     * Initializes the window. Creates all the labels used.
     */
    void Initialize(GameManager& game_manager) override;
};