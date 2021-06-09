#include "game_window.h"

GameWindow::GameWindow(const string& _name, const int& width, const int& height, const IVector2& position)
: BaseWindow(width, height, position, COLOR_WHITE, COLOR_BLACK)
{
    name = _name;
}

GameWindow::GameWindow(const string& _name, const int& width, const int& height, const IVector2& position, const WindowBorder& border)
: BaseWindow(width, height, position, border , COLOR_WHITE, COLOR_BLACK)
{
    name = _name;
}

void GameWindow::Draw(const Drawer& drawer) const
{
    drawer.SetWindow(windowWrapper);
    drawer.Clear();
    drawer.SetColor(foregroundColor, backgroundColor);
    drawer.DrawWindowBorder();
    drawer.Refresh();
}