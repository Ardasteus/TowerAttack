#include "gui_window.h"

#define KEY_TAB 9

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
    drawer.SetWindow(windowWrapper);
    drawer.Clear();
    drawer.SetColor(foregroundColor, backgroundColor);
    drawer.DrawWindowBorder();
    for(auto element : gui_elements)
    {
        IVector2 offset(1,1);
        element->Draw(drawer, offset);
    }
    drawer.Refresh();
}

void GUIWindow::AddElement(GUIObject* element)
{
    shared_ptr<GUIObject> to_add (element);
    FocusableGUIObject* focusable = dynamic_cast<FocusableGUIObject*>(element);
    if(focusable != nullptr)
    {
        focusable_elements.push_back(focusable);
        focused_element = 0;
        focusable_elements[focused_element]->isCurrentlyFocused = true;
    }
    gui_elements.push_back(to_add);
}

void GUIWindow::HandleInput(const int key)
{
    if(focusable_elements.size() == 0)
        return;
    if(key == KEY_RIGHT)
    {
        focusable_elements[focused_element++]->isCurrentlyFocused = false;
        if(focused_element == (int)focusable_elements.size())
            focused_element = 0;

        focusable_elements[focused_element]->isCurrentlyFocused = true;
    }
    else if(key == KEY_LEFT)
    {
        focusable_elements[focused_element--]->isCurrentlyFocused = false;
        if(focused_element == -1)
                focused_element = (int)focusable_elements.size() - 1;

        focusable_elements[focused_element]->isCurrentlyFocused = true;
    }
    else
        focusable_elements[focused_element]->HandleInput(key);
}