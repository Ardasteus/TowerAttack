#include "game_object.h"

GameObject::GameObject(const string& _name, const IVector2& _position, char _draw_character, const short& fg, const short& bg)
{
    name = _name;
    position = _position;
    draw_character = _draw_character;
    foreground = fg;
    background = bg;
}