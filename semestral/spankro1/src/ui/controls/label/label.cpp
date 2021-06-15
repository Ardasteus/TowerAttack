#include "label.h"

Label::Label(const std::string& name, const std::string& caption, 
const IVector2& position, const int& width, const short& fg, const short& bg) : GUIObject(name, position, width, 1, fg, bg)
{
    text = caption;
}

void Label::Draw(const Drawer& drawer, const IVector2& offset)
{
    drawer.SetColor(foreground, background);
    string print = text;
    if((int)text.size() > width)
        print = text.substr(0, width - 1);

    drawer.DrawString(print, offset + position);
}

void Label::UpdateText(const string& new_text)
{
    text = new_text;
}