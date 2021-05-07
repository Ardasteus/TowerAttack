#include "gui_window.h"

GUIWindow::GUIWindow(const string& _name, const int& width, const int& height, const IVector2& position) 
: BaseWindow(width, height, position, COLOR_WHITE, COLOR_BLACK)
{
    name = _name;
}

GUIWindow::GUIWindow(const string& _name, const int& width, const int& height, const IVector2& position, const WindowBorder& border) 
: BaseWindow(width, height, position, border , COLOR_WHITE, COLOR_BLACK)
{
    name = _name;
}

GUIWindow::~GUIWindow()
{
    
}

void GUIWindow::Draw(const Drawer& drawer) const
{
    drawer.SetWindow(windowWrapper);
    drawer.DrawWindowBorder();
    for(auto element : guiElements)
    {
        IVector2 offset(1,1);
        element->Draw(drawer, offset);
    }
}

void GUIWindow::AddElement(GUIObject* element)
{
    shared_ptr<GUIObject> to_add (element);
    guiElements.push_back(to_add);
}