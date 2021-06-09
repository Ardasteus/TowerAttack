#pragma once

using namespace std;

#include "graphics/window/base_window.h"
#include "game/game_object/game_object.h"
#include <list>
#include <memory>

class GameWindow : public BaseWindow
{
private:
    string name;
public:
    GameWindow(const string& _name, const int& width, const int& height, const IVector2& position);
    GameWindow(const string& _name, const int& width, const int& height, const IVector2& position, const WindowBorder& border);

    void Draw(const Drawer& drawer) const override;
};