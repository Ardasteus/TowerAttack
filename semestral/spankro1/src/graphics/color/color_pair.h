#pragma once

#include "ncurses.h"

class ColorPair
{
private:
    short id;
    short foreground;
    short background;
public:
    ColorPair(const short& _id, const short& fg, const short& bg);
    ~ColorPair();

    int GetId() const;
    int GetForeground() const;
    int GetBackground() const;
};
