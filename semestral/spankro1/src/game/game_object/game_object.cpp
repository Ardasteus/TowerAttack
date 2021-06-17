#include "game_object.h"
#include "core/game_manager/game_manager.h"

GameObject::GameObject()
{
    name = "Default";
    position = IVector2(0,0);
    previous_position = IVector2(0,0);
    draw_character = 'D';
    foreground = COLOR_RED;
    background = COLOR_YELLOW;
    update_time = 0;
    current_update_time = 0;
    on_destroy = nullptr;
}

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
    on_destroy = nullptr;
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
    on_destroy = nullptr;
}

void GameObject::SetOnDestroyCallback(const function<void(const IVector2&)>& func)
{
    on_destroy = func;
}

void GameObject::Draw(const Drawer& drawer, const IVector2& offset)
{
    drawer.SetColor(foreground, background);
    drawer.DrawChar(draw_character, offset + position);
}

const string& GameObject::GetName() const
{
    return name;
}

const IVector2& GameObject::GetPosition() const
{
    return position;
}

void GameObject::InvokeOnDestroy()
{
    if(on_destroy != nullptr)
        on_destroy(position);
}

void GameObject::SetPosition(const IVector2& pos)
{
    position = pos;
}