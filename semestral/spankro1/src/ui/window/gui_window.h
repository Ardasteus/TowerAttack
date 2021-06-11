#pragma once

using namespace std;

#include "graphics/window/base_window.h"
#include "ui/controls/gui_object/gui_object.h"
#include "ui/controls/focusable_gui_object/focusable_gui_object.h"
#include <list>
#include <memory>

class GUIWindow : public BaseWindow
{
private:
    list<shared_ptr<GUIObject>> gui_elements;
    vector<FocusableGUIObject*> focusable_elements;
    int focused_element;
    string name;
public:
    GUIWindow();
    GUIWindow(const string& _name, const int& width, const int& height, const IVector2& position);
    GUIWindow(const string& _name, const int& width, const int& height, const IVector2& position, const WindowBorder& border);
    ~GUIWindow();

    void Draw(const Drawer& drawer) const override;
    void HandleInput(const int key);
    void AddElement(shared_ptr<GUIObject> element);
};