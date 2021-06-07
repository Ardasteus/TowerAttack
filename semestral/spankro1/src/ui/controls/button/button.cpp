#include "button.h"

Button::Button(const std::string& name, const std::string& _caption, const IVector2& _position, const int& width, 
const short& _foreground, const short& _background, const short& _fforeground, const short& _fbackground)
: FocusableGUIObject(name, _position, width, 1, _foreground, _background, _fforeground, _fbackground)
{
    caption = _caption;
}

void Button::HandleInput(const int key)
{
    //Enter
    if(key == 10)
    {
        for(auto func : on_click_functions)
            func();
    }
}

void Button::Draw(const Drawer& drawer, const IVector2& offset) const
{
    if(isCurrentlyFocused)
        drawer.SetColor(focusedForegound, focusedBackground);
    else
        drawer.SetColor(foreground, background);

    string print = caption;
    if(caption.size() > width)
        print = caption.substr(0, width - 1);

    drawer.DrawString(print, offset + position);
}

void Button::AddOnClickEvent(function<void()> func)
{
    on_click_functions.push_back(func);
}