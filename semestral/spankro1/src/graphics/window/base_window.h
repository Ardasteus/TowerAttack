#pragma once

using namespace std;

#include "ncurses.h"
#include "graphics/window/window_border.h"
#include "math/vector/ivector2.h"
#include "graphics/idrawable/idrawable.h"
#include <memory>
#include <functional>

/**
 * Base class for all windows used in the game.
 */
class BaseWindow : public IDrawable
{
protected:
    WINDOW* handle;
    IVector2 position;
    WindowBorder border;
    int width;
    int height;

    /**
     * Foreground color of the window.
     */
    int foreground_color;
    /**
     * Background color of the window.
     */
    int background_color;

    function<void(string)> on_window_change;
public:
    /**
     * Constructor with default WindowBorder.
     * 
     * @param _width Width of the window
     * @param _height Height of the window
     * @param _position Position of the window
     * @param fg Foreground color
     * @param bg Background color
     */
    BaseWindow(const int& _width, const int& _height, const IVector2& _position, const int& fg, const int& bg);

    /**
     * Constructor with default border.
     * 
     * @param _width Width of the window
     * @param _height Height of the window
     * @param _position Position of the window
     * @param fg Foreground color
     * @param bg Background color
     * @param _border Custom WindowBorder
     */
    BaseWindow(const int& _width, const int& _height, const IVector2& _position, const int& fg, const int& bg, const WindowBorder& _border);

    /**
     * Default destructor
     */
    virtual ~BaseWindow();

    /**
     * Initializes the window.
     */
    virtual void Initialize();

    /**
     * Draws the window.
     * 
     * Tells the drawer to use this window for all future drawing calls and draws the border.
     * 
     * @param drawer Drawer to be used
     */
    virtual void Draw(const Drawer& drawer, const IVector2&) override;

    void SetOnWindowChange(const function<void(string)>& func);
};