#include "window.h"

Window::Window(const int& width, const int& height, const IVector2& position)
{
    window = WindowWrapper(width, height, position);
}

Window::Window(const int& width, const int& height, const IVector2& position, const WindowBorder& border)
{
    window = WindowWrapper(width, height, position, border);
}

Window::~Window()
{
    
}

void Window::Draw(const Drawer& drawer) const
{
    
}