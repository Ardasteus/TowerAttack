#pragma once

using namespace std;

#include <vector>
#include <functional>
#include "ui/controls/focusable_gui_object/focusable_gui_object.h"

class Button : public FocusableGUIObject
{
private:
    string caption; 
    vector<function<void()>> on_click_functions;

public:
    Button(const std::string& name, const std::string& _caption, const IVector2& _position, const int& width, 
    const short& _foreground, const short& _background, const short& _fforeground, const short& _fbackground);

    void HandleInput(const int key) override;
    void Draw(const Drawer& drawer, const IVector2& offset) const override;

    void AddOnClickEvent(function<void()> func);
};