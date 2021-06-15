#include "drawer.h"

Drawer::Drawer()
{
    window = nullptr;
    colorEnabled = false;
}

Drawer::~Drawer()
{
    endwin();
}

void Drawer::Initialize()
{
    initscr();
    raw();
    noecho();
    nodelay(stdscr, TRUE);
    keypad(stdscr, true);
    curs_set(0);
    colorEnabled = has_colors();
    if(colorEnabled)
    {
        start_color();
    }
}

void Drawer::ClearAll() const
{
    erase();
    refresh();
}


void Drawer::Clear() const
{
    if(window != nullptr)
        werase(window);
}

void Drawer::Refresh() const
{
    if(window != nullptr)
        wrefresh(window);
}

void Drawer::SetWindow(WINDOW* window_handle) const
{
    window = window_handle;
}

void Drawer::SetColor(const short& foreground, const short& background) const
{
    if(!colorEnabled || window == nullptr)
        return;

    short new_id = (short)colors.size() + 1;
    ColorPair pair(new_id, foreground, background);
    auto pair_found = colors.find(pair);
    if(pair_found == colors.end())
    {
        init_pair(new_id, foreground, background);
        colors.insert(pair);
    }
    else
        pair = *pair_found;
    
    wattron(window, COLOR_PAIR(pair.GetId()));
}

void Drawer::DrawWindowBorder(const WindowBorder& border) const
{
    if(window == nullptr)
        return;
    std::vector<char> border_chars = border.GetBorderCharacters();
    wborder(window, border_chars[0], border_chars[1], border_chars[2], border_chars[3], 
    border_chars[4], border_chars[5], border_chars[6], border_chars[7]);
}

void Drawer::DrawChar(const char& character, const IVector2& position) const
{
    mvwaddch(window, position.GetY(), position.GetX(), character);
}

void Drawer::DrawString(const std::string& text, const IVector2& position) const
{
    mvwaddstr(window, position.GetY(), position.GetX(), text.c_str());
}