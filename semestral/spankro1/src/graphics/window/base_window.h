#pragma once

#include "graphics/window/window_wrapper.h"
#include "graphics/drawer/drawer.h"
#include "math/vector/ivector2.h"
#include <memory> 

class BaseWindow
{
protected:
    std::shared_ptr<WindowWrapper> windowWrapper;
    int foregroundColor;
    int backgroundColor;
public:
    BaseWindow(const int& width, const int& height, const IVector2& position, const int& fg, const int& bg);
    BaseWindow(const int& width, const int& height, const IVector2& position, const WindowBorder& border, const int& fg, const int& bg);
    ~BaseWindow();

    virtual void Initialize() const;
    virtual void Draw(const Drawer& drawer) const;
};