#pragma once

using namespace std;

#include "ui/window/gui_window.h"
#include "ui/control_creator/control_creator.h"
#include "interfaces/iinitializable.h"

class AttackerPickerWindow : public GUIWindow, public IInitializable
{
public:

    using BaseWindow::Initialize;

    AttackerPickerWindow(const int& width, const int& height, const IVector2& position);

    ~AttackerPickerWindow();

    /**
     * Initializes the window. Creates all the labels used.
     */
    void Initialize(GameManager& game_manager) override;
};