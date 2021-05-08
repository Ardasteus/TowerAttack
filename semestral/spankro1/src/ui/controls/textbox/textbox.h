#pragma once

#include "ui/controls/focusable_gui_object/focusable_gui_object.h"

class Textbox : public FocusableGUIObject
{
private:
    std:: string value;
public:
    Textbox(const std::string& name, const std::string& _initial_value, const IVector2& _position, const int& width, 
    const short& _foreground, const short& _background, const short& _fforeground, const short& _fbackground);

    void HandleInput(const int key) override;
    void Draw(const Drawer& drawer, const IVector2& offset) const override;
};