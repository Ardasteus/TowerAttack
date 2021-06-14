#pragma once

#include "ncurses.h"
#include "math/vector/ivector2.h"
#include "window_border.h"

/**
 * Wraps the ncurses WINDOW class and its border.
 */
class WindowWrapper
{
protected:
    /**
     * Pointer to ncurses window
     */
    WINDOW* handle = nullptr;

    /**
     * Position of the window
     */
    IVector2 position;

    /**
     * Border of the window
     */
    WindowBorder border;

    /**
     * Width of the window
     */
    int width;

    /**
     * Height of the window
     */
    int height;
public:
    /**
     * Default constructor
     */
    WindowWrapper();

    /**
     * Copy constructor
     */
    WindowWrapper(const WindowWrapper& other);

    /**
     * Constructor with default border
     * 
     * Default border is made out of + - and | characters.
     * 
     * @param _width Width of the window
     * @param _height Height of the window
     * @param _position Position of the window
     */
    WindowWrapper(const int& _width, const int& _height, const IVector2& _position);

    /**
     * Constructor with custom border.
     * 
     * @param _width Width of the window
     * @param _height Height of the window
     * @param _position Position of the window
     * @param _border Border of the window
     */
    WindowWrapper(const int& _width, const int& _height, const IVector2& _position, const WindowBorder& _border);

    /**
     * Default destructor
     */
    ~WindowWrapper();

    /**
     * Initializes the window.
     */
    void Initialize();

    /**
     * Returns the pointer to ncurses WINDOW
     * 
     * @return Pointer to ncurses WINDOW
     */
    WINDOW* GetWindow() const;

    /**
     * Returns the position of the window
     * 
     * @return Copy of the position vector
     */
    const IVector2& GetPosition() const;

    /**
     * Returns the position of the window
     * 
     * @return WindowBorder object
     */
    const WindowBorder& GetBorder() const;

    /**
     * Returns width of the window
     * 
     * @returns Width integer
     */
    const int& GetWidth() const;

    /**
     * Returns height of the window
     * 
     * @returns Height integer
     */
    const int& GetHeight() const;
};