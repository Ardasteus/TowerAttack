#include "gui_window.h"

#define KEY_TAB 9

GUIWindow::GUIWindow() 
: BaseWindow(0, 0, IVector2(0,0), COLOR_WHITE, COLOR_BLACK)
{
    name = "Default";
    focused_element = -1;
}

GUIWindow::GUIWindow(const string& _name, const int& width, const int& height, const IVector2& position) 
: BaseWindow(width, height, position, COLOR_WHITE, COLOR_BLACK)
{
    name = _name;
    focused_element = -1;
}

GUIWindow::GUIWindow(const string& _name, const int& width, const int& height, const IVector2& position, const WindowBorder& border) 
: BaseWindow(width, height, position, border , COLOR_WHITE, COLOR_BLACK)
{
    name = _name;
    focused_element = -1;
}

GUIWindow::~GUIWindow()
{
    gui_elements.empty();
}

void GUIWindow::Draw(const Drawer& drawer) const
{
    drawer.SetWindow(window_wrapper);
    drawer.Clear();
    drawer.SetColor(foreground_color, background_color);
    drawer.DrawWindowBorder();
    for(auto element : gui_elements)
    {
        IVector2 offset(1,1);
        element->Draw(drawer, offset);
    }
    drawer.Refresh();
}

void GUIWindow::AddElement(shared_ptr<GUIObject> element)
{
    FocusableGUIObject* focusable = dynamic_cast<FocusableGUIObject*>(element.get());
    if(focusable != nullptr)
    {
        focusable_elements.push_back(focusable);
        focused_element = 0;
        focusable_elements[focused_element]->is_currently_focused = true;
    }
    gui_elements.push_back(element);
}

void GUIWindow::HandleInput(const int key)
{
    if(focusable_elements.size() == 0)
        return;
    if(key == KEY_DOWN)
    {
        focusable_elements[focused_element++]->is_currently_focused = false;
        if(focused_element == (int)focusable_elements.size())
            focused_element = 0;

        focusable_elements[focused_element]->is_currently_focused = true;
    }
    else if(key == KEY_UP)
    {
        focusable_elements[focused_element--]->is_currently_focused = false;
        if(focused_element == -1)
                focused_element = (int)focusable_elements.size() - 1;

        focusable_elements[focused_element]->is_currently_focused = true;
    }
    else
        focusable_elements[focused_element]->HandleInput(key);
}