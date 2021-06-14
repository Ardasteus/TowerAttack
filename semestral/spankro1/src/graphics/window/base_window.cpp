#include "base_window.h"

BaseWindow::BaseWindow(const int& width, const int& height, const IVector2& position, const int& fg, const int& bg)
{
    window_wrapper = std::make_shared<WindowWrapper>(WindowWrapper(width, height, position));
    foreground_color = fg;
    background_color = bg;
}

BaseWindow::BaseWindow(const int& width, const int& height, const IVector2& position, const WindowBorder& border, const int& fg, const int& bg)
{
    window_wrapper = std::make_shared<WindowWrapper>(WindowWrapper(width, height, position, border));
    foreground_color = fg;
    background_color = bg;
}

BaseWindow::~BaseWindow()
{
    
}

void BaseWindow::Initialize() const
{
    window_wrapper.get()->Initialize();
}

void BaseWindow::Draw(const Drawer& drawer) const
{
    drawer.SetWindow(window_wrapper);
    drawer.SetColor(foreground_color, background_color);
    drawer.DrawWindowBorder();
    drawer.Refresh();
}