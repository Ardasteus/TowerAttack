#include "game_object.h"

GameObject::GameObject(const string& _name, const IVector2& _position, char _draw_character, const short& fg, const short& bg)
{
    name = _name;
    position = _position;
    previous_position = _position;
    draw_character = _draw_character;
    foreground = fg;
    background = bg;
    update_time = 0;
    current_update_time = 0;
    onDestroy = nullptr;
}

GameObject::GameObject(const string& _name, const IVector2& _position, char _draw_character, const short& fg, const short& bg, int _update_time)
{
    name = _name;
    position = _position;
    previous_position = _position;
    draw_character = _draw_character;
    foreground = fg;
    background = bg;
    update_time = _update_time;
    current_update_time = 0;
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

const string GameObject::GetName() const
{
    return name;
}

const IVector2 GameObject::GetPosition() const
{
    return position;
}