#include "button.h"

Button::Button(const std::string& name, const std::string& _caption, const IVector2& position, const int& width, 
const short& fg, const short& bg, const short& ffg, const short& fbg)
: FocusableGUIObject(name, position, width, 1, fg, bg, ffg, fbg)
{
    caption = _caption;
}

void Button::HandleInput(const int& key, GameManager& game_manager)
{
    //Enter
    if(key == 10)
    {
        for(const auto& func : on_click_functions)
            func(game_manager);
    }
}

void Button::Draw(const Drawer& drawer, const IVector2& offset)
{
    if(is_currently_focused)
        drawer.SetColor(focused_foregound, focused_background);
    else
        drawer.SetColor(foreground, background);

    for (int i = 0; i < width; i++)
        drawer.DrawChar(' ', offset + position + IVector2(i,0));

    string print = caption;
    if((int)caption.size() > width)
        print = caption.substr(0, width - 1);

    drawer.DrawString(print, offset + position);
}

void Button::AddOnClickEvent(function<void(GameManager&)> func)
{
    on_click_functions.push_back(func);
}