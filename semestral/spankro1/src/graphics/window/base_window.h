#pragma once

#include "graphics/window/window_wrapper.h"
#include "graphics/drawer/drawer.h"
#include "math/vector/ivector2.h"
#include <memory> 

/**
 * Base class for all windows used in the game.
 */
class BaseWindow
{
protected:
    /**
     * Pointer to WindowWrapper class.
     */
    std::shared_ptr<WindowWrapper> window_wrapper;

    /**
     * Foreground color of the window.
     */
    int foreground_color;
    /**
     * Background color of the window.
     */
    int background_color;
public:
    /**
     * Constructor with default WindowBorder.
     * 
     * @param width Width of the window
     * @param height Height of the window
     * @param position Position of the window
     * @param fg Foreground color
     * @param bg Background color
     */
    BaseWindow(const int& width, const int& height, const IVector2& position, const int& fg, const int& bg);

    /**
     * Constructor with default border.
     * 
     * @param width Width of the window
     * @param height Height of the window
     * @param position Position of the window
     * @param border Custom WindowBorder
     * @param fg Foreground color
     * @param bg Background color
     */
    BaseWindow(const int& width, const int& height, const IVector2& position, const WindowBorder& border, const int& fg, const int& bg);

    /**
     * Default destructor
     */
    ~BaseWindow();

    /**
     * Initializes the window.
     */
    virtual void Initialize() const;

    /**
     * Draws the window.
     * 
     * Tells the drawer to use this window for all future drawing calls and draws the border.
     * 
     * @param drawer Drawer to be used
     */
    virtual void Draw(const Drawer& drawer) const;
};