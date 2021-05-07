#pragma once

using namespace std;

#include "graphics/window/base_window.h"
#include "ui/controls/gui_object/gui_object.h"
#include <list>
#include <memory>

class GUIWindow : public BaseWindow
{
private:
    list<shared_ptr<GUIObject>> guiElements;
    string name;
public:
    GUIWindow(const string& _name, const int& width, const int& height, const IVector2& position);
    GUIWindow(const string& _name, const int& width, const int& height, const IVector2& position, const WindowBorder& border);
    ~GUIWindow();

    void Draw(const Drawer& drawer) const override;
    void AddElement(GUIObject* element);
};