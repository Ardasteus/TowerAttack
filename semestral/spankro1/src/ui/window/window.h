#pragma once

#include "graphics/window/window_wrapper.h"
#include "graphics/drawer/drawer.h"

class Window
{
private:
    WindowWrapper window;

public:
    Window(const int& width, const int& height, const IVector2& position);
    Window(const int& width, const int& height, const IVector2& position, const WindowBorder& border);
    ~Window();

    void Draw(const Drawer& drawer) const;
};