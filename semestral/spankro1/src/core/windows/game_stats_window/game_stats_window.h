#pragma once

using namespace std;

#include "core/game_stats/game_stats.h"
#include "ui/window/gui_window.h"
#include "ui/control_creator/control_creator.h"
#include "interfaces/iinitializable.h"
#include "core/game_stats/game_stats.h"
#include <map>

/**
 * Encapsulates a GUIWindow with Label objects that show relevant GameStats information
 */
class GameStatsWindow : public GUIWindow, public IInitializable
{
protected:

    /**
     * Map of Labels for easy access
     */
    map<string, shared_ptr<Label>> labels;
public:

    using BaseWindow::Initialize;

    /**
     * Creates a new GameStats window handler
     * 
     * @param width Width of the window
     * @param height Height of the window
     * @param position Position of the window
     */
    GameStatsWindow(const int& width, const int& height, const IVector2& position);

    /**
     * Default destructor
     */
    ~GameStatsWindow();

    /**
     * Initializes the window. Creates all the labels used.
     * 
     * @param game_manager GameManager instance to be used
     */
    void Initialize(GameManager& game_manager) override;

    /**
     * Updates the label values with values taken from given GameStats instance
     * 
     * @param game_stats GameStats instance to update from
     */
    void UpdateWindow(const GameStats& game_stats);
};
