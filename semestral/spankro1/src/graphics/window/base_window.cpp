#include "base_window.h"

BaseWindow::BaseWindow(const int& width, const int& height, const IVector2& position, const int& fg, const int& bg)
{
    windowWrapper = std::make_shared<WindowWrapper>(WindowWrapper(width, height, position));
    foregroundColor = fg;
    backgroundColor = bg;
}

BaseWindow::BaseWindow(const int& width, const int& height, const IVector2& position, const WindowBorder& border, const int& fg, const int& bg)
{
    windowWrapper = std::make_shared<WindowWrapper>(WindowWrapper(width, height, position, border));
    foregroundColor = fg;
    backgroundColor = bg;
}

BaseWindow::~BaseWindow()
{
    
}

void BaseWindow::Initialize() const
{
    windowWrapper.get()->Initialize();
}

void BaseWindow::Draw(const Drawer& drawer) const
{
    drawer.SetWindow(windowWrapper);
    drawer.SetColor(foregroundColor, backgroundColor);
    drawer.DrawWindowBorder();
    drawer.Refresh();
}