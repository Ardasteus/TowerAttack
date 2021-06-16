#pragma once

using namespace std;

#include "interfaces/iinitializable.h"
#include "ui/window/gui_window.h"
#include "ui/control_creator/control_creator.h"
#include "core/windows/game_stats_window/game_stats_window.h"
#include "core/windows/attacker_picker_window/attacker_picker_window.h"

class GameWindow : public GUIWindow, public IInitializable
{
protected:
    GameStatsWindow stats_window;
    AttackerPickerWindow attacker_picker;

public:
    GameWindow();

    ~GameWindow();

    void HandleInput(const int& key, GameManager& game_manager) override;

    void Initialize() override;

    void Draw(const Drawer& drawer, const IVector2& offset);

    /**
     * Initializes the window. Creates all the labels used.
     */
    void Initialize(GameManager& game_manager) override;
};