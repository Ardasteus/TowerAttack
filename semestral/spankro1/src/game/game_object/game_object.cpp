#include "game_object.h"

GameObject::GameObject(const string& _name, const IVector2& _position, char _draw_character, const short& fg, const short& bg)
{
    name = _name;
    position = _position;
    draw_character = _draw_character;
    foreground = fg;
    background = bg;
    onDestroy = nullptr;
}

void GameObject::SetOnDestroyCallback(function<void(IVector2)> func)
{
    onDestroy = func;
}

void GameObject::Draw(const Drawer& drawer, const IVector2& offset) const
{
    drawer.SetColor(foreground, background);
    drawer.DrawChar(draw_character, offset + position);
}