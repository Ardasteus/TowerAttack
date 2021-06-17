#include "base_window.h"

BaseWindow::BaseWindow(const int& _width, const int& _height, const IVector2& _position, const int& fg, const int& bg)
{
    width = _width;
    height = _height;
    position = _position;
    border = WindowBorder();
    foreground_color = fg;
    background_color = bg;
    on_window_change = nullptr;
}

BaseWindow::BaseWindow(const int& _width, const int& _height, const IVector2& _position, const int& fg, const int& bg, const WindowBorder& _border)
{
    width = _width;
    height = _height;
    position = _position;
        border = _border;
    foreground_color = fg;
    background_color = bg;
    on_window_change = nullptr;
}

BaseWindow::~BaseWindow()
{
    if(handle != nullptr)
        delwin(handle);
}

void BaseWindow::Initialize()
{
    handle = newwin(height, width, position.GetY(), position.GetX());
    box(handle, ' ', ' ');
}

void BaseWindow::Draw(const Drawer& drawer, const IVector2&)
{
    drawer.SetWindow(handle);
    drawer.SetColor(foreground_color, background_color);
    drawer.DrawWindowBorder(border);
    drawer.Refresh();
}

void BaseWindow::SetOnWindowChange(const function<void(string)>& func)
{
    on_window_change = func;
}