#include "drawer.h"

Drawer::Drawer()
{
    colorEnabled = false;
}

Drawer::~Drawer()
{
    
}

WINDOW* Drawer::GetWindow() const
{
    WindowWrapper* window = currentWindow.get();
    return window->GetWindow();
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

void Drawer::Refresh()
{
    wrefresh(GetWindow());
}

void Drawer::SetWindow(const std::shared_ptr<WindowWrapper>& window) const
{
    currentWindow = window;
}

void Drawer::Dispose()
{
    endwin();
}

void Drawer::SetColor(const short foreground, const short background) const
{
    if(!colorEnabled)
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
    
    wattron(GetWindow(), COLOR_PAIR(pair.GetId()));
}

void Drawer::DrawWindowBorder() const
{
    WindowWrapper* window = currentWindow.get();
    std::vector<char> border = window->GetBorder().GetBorderCharacters();
    WINDOW* _window = window->GetWindow();
    wborder(_window, border[0], border[1], border[2], border[3], border[4], border[5], border[6], border[7]);
}

void Drawer::DrawChar(const char character, const IVector2 position) const
{
    mvwaddch(GetWindow(), position.GetY(), position.GetX(), character);
}

void Drawer::DrawString(const std::string text, const IVector2 position) const
{
    mvwaddstr(GetWindow(), position.GetY(), position.GetX(), text.c_str());
}