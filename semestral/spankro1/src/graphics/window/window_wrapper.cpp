#include "window_wrapper.h"

WindowWrapper::WindowWrapper()
{
    width = 0;
    height = 0;
    position = IVector2();
    border = WindowBorder();
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
    if(handle != nullptr)
    {
        delwin(handle);
    }
}

void WindowWrapper::Initialize()
{
    handle = newwin(height, width, position.GetY(), position.GetX());
}

const WINDOW* WindowWrapper::GetWindow() const
{
    return handle;
}

const IVector2 WindowWrapper::GetPosition() const
{
    return position;
}

const WindowBorder WindowWrapper::GetBorder() const
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