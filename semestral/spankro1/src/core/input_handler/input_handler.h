#pragma once

#include "ncurses.h"

class InputHandler
{
private:
    WINDOW* input_window;
public:
    InputHandler();

    void Initialize();
    int HandleInput() const;
    void Dispose();
};