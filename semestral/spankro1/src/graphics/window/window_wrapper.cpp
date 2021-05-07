#include "window_wrapper.h"

WindowWrapper::WindowWrapper()
{
    width = 0;
    height = 0;
    position = IVector2();
    border = WindowBorder();
}

WindowWrapper::WindowWrapper(const WindowWrapper& other)
{
    width = other.width;
    height = other.height;
    position = other.position;
    border = other.border;
    handle = other.handle;
}

WindowWrapper::WindowWrapper( const int& _width, const int& _height, const IVector2& _position)
{
    width = _width;
    height = _height;
    position = _position;
    border = WindowBorder();
}

WindowWrapper::WindowWrapper(const int& _width, const int& _height, const IVector2& _position, const WindowBorder& _border)
{
    width = _width;
    height = _height;
    position = _position;
    border = _border;
}

WindowWrapper::~WindowWrapper()
{  
    delwin(handle);
}

void WindowWrapper::Initialize()
{
    handle = newwin(height, width, position.GetY(), position.GetX());
    box(handle, ' ', ' ');
}

WINDOW* WindowWrapper::GetWindow() const
{
    return handle;
}

IVector2 WindowWrapper::GetPosition() const
{
    return position;
}

WindowBorder WindowWrapper::GetBorder() const
{
    return border;
}

int WindowWrapper::GetWidth() const
{
    return width;
}

int WindowWrapper::GetHeight() const
{
    return height;
}