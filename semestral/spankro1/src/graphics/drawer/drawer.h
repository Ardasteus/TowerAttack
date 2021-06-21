#pragma once

#include "ncurses.h"
#include <string>
#include <memory>
#include <set>
#include <vector>
#include "graphics/window/window_border.h"
#include "graphics/color/color_pair.h"
#include "graphics/color/color_pair_comparator.h"
#include "math/vector/ivector2.h"

/**
 * Responsible for all drawing in this game.
 */
class Drawer
{
protected:
    /**
     * Pointer to current window.
     * 
     * Is mutable so it can be used in const Draw calls.
     */
    mutable WINDOW* window;

    /**
     * Set of color pairs, used to keep track of used colors.
     * 
     * Is mutable so it can be used in const Draw calls.
     */
    mutable std::set<ColorPair, ColorPairComparator> colors;

    /**
     * Bool indicating whether colors can be used.
     */
    bool colorEnabled;

public:
    /**
     * Default constructor
     */
    Drawer();

    /**
     * Default deconstructor.
     */
    ~Drawer();

    /**
     * Initializes ncurses
     */
    void Initialize();

    /**
     * Turns off Ncurses
     */
    void Dispose();

    /**
     * Clears the entire screen.
     * 
     * Used mainly when switching windows to wipe the whole screen.
     */
    void ClearAll() const;

    /**
     * Clears the content of current window.
     */
    void Clear() const;

    /**
     * Refreshes the window, thus drawing any changes.
     */
    void Refresh() const;

    /**
     * Sets current window, any further function calls will be executed in the context of this window.
     * 
     * @param window_handle Pointer to a window to be set as the current window.
     */
    void SetWindow(WINDOW* window_handle) const;

    /**
     * Sets the colors to be used for all drawing calls in current window.
     * 
     * @param foreground Foreground color
     * @param background Background color
     */
    void SetColor(const short& foreground, const short& background) const;

    /**
     * Draws the border of the current window
     */
    void DrawWindowBorder(const WindowBorder& border) const;

    /**
     * Draws a character at specific position
     * 
     * @param character Character to be drawn
     * @param position Position to draw at
     */
    void DrawChar(const char& character, const IVector2& position) const;

    /**
     * Draws a string at specific location
     * 
     * @param text String to be drawn
     * @param position Position to draw at
     */
    void DrawString(const std::string& text, const IVector2& position) const;
};
