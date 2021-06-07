#include "textbox.h"

Textbox::Textbox(const std::string& name, const std::string& _initial_value, const IVector2& _position, const int& width, 
const short& _foreground, const short& _background, const short& _fforeground, const short& _fbackground)
: FocusableGUIObject(name, _position, width, 1, _foreground, _background, _fforeground, _fbackground)
{
    value = _initial_value;
}

void Textbox::HandleInput(const int key)
{
    char to_add = (char)key;
    if(to_add == '\a')
    {
        string new_val = value.substr(0, value.size() - 1);
        value = new_val;
    }
    else if(key < 32)
        return;
    else
        value += to_add;
}

void Textbox::Draw(const Drawer& drawer, const IVector2& offset) const
{
    if(isCurrentlyFocused)
        drawer.SetColor(focusedForegound, focusedBackground);
    else
        drawer.SetColor(foreground, background);

    string print = value;
    if(value.size() > width)
        print = value.substr(0, width - 1);

    drawer.DrawString(print, offset + position);
}