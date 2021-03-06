#include "textbox.h"

Textbox::Textbox(const std::string& name, const std::string& initial_value, const IVector2& position, const int& width, 
const short& fg, const short& bg, const short& ffg, const short& fbg)
: FocusableGUIObject(name, position, width, 1, fg, bg, ffg, fbg)
{
    value = initial_value;
}

void Textbox::HandleInput(const int& key, GameManager&)
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

void Textbox::Draw(const Drawer& drawer, const IVector2& offset)
{
    if(is_currently_focused)
        drawer.SetColor(focused_foregound, focused_background);
    else
        drawer.SetColor(foreground, background);


    for (int i = 0; i < width; i++)
        drawer.DrawChar(' ', offset + position + IVector2(i,0));
    

    string print = value;
    if((int)value.size() > width)
        print = value.substr(0, width - 1);

    drawer.DrawString(print, offset + position);
}