#pragma once

#include "ncurses.h"
#include "math/vector/ivector2.h"
#include "window_border.h"

class WindowWrapper
{
private:
    WINDOW* handle = nullptr;
    IVector2 position;
    WindowBorder border;

    int width;
    int height;
public:
    WindowWrapper();
    WindowWrapper(const int& _width, const int& _height, const IVector2& _position);
    WindowWrapper(const int& _width, const int& _height, const IVector2& _position, const WindowBorder& _border);
    ~WindowWrapper();
    void Initialize();

    const WINDOW* GetWindow() const;
    const IVector2 GetPosition() const;
    const WindowBorder GetBorder() const;
    int GetWidth() const;
    int GetHeight() const;
};