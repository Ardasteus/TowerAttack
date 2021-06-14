#pragma once

using namespace std;

#include "core/game_stats/game_stats.h"
#include "ui/window/gui_window.h"
#include "ui/controls/label/label.h"
#include "ui/control_creator/control_creator.h"
#include <map>

/**
 * Encapsulates a GUIWindow with Label objects that show relevant GameStats information
 */
class GameStatsWindowHandler
{
protected:
    /**
     * GUIWindow that is used
     */
    GUIWindow window;

    /**
     * Map of Labels for easy access
     */
    map<string, shared_ptr<Label>> labels;
public:
    /**
     * Creates a new GameStats window handler
     * 
     * @param width Width of the window
     * @param height Height of the window
     * @param position Position of the window
     */
    GameStatsWindowHandler(const int& width, const int& height, const IVector2& position);

    /**
     * Initializes the window. Creates all the labels used.
     */
    void Initialize();

    /**
     * Updates the label values with values taken from given GameStats instance
     * 
     * @param stats GameStats instance to update from
     */
    void UpdateWindow(const GameStats& stats);

    /**
     * Draws the window
     * 
     * @param drawer Drawer instance to be used
     */
    void Draw(const Drawer& drawer) const;

    /**
     * Disposes of all resources used.
     */
    void Dispose();
};
