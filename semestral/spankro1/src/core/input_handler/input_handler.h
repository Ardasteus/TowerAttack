#pragma once

#include "ncurses.h"

/**
 * Has a ncurses WINDOW class that is used to accept all user input in the app
 */
class InputHandler
{
protected:
    /**
     * Pointer to the ncurses WINDOW
     * 
     * Just a dummy 0 width, 0 height window
     */
    WINDOW* input_window;
public:
    /**
     * Default constructor
     */
    InputHandler();

    ~InputHandler();

    /**
     * Initializes the window
     */
    void Initialize();

    /**
     * Acceps user input and outputs the code of the key pressed
     * 
     * @return Key code
     */
    int HandleInput() const;
};