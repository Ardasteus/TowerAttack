#include "label.h"

Label::Label(const std::string& _name, const std::string& _text, 
const IVector2& _position, const int& _width, const short& _foreground, const short& _background) : GUIObject(_name, _position, _width, 1, _foreground, _background)
{
    text = _text;
}

void Label::Draw(const Drawer& drawer, const IVector2& offset) const
{
    drawer.SetColor(foreground, background);
    string print = text;
    if(text.size() > width)
        print = text.substr(0, width - 1);

    drawer.DrawString(print, offset + position);
}