#pragma once

#include "ui/controls/gui_object/gui_object.h"
#include <string>

class Label : public GUIObject
{
private:
    std::string text;
public:
    Label(const std::string& name, const std::string& _text, const IVector2& _position, const int& width, const short& _foreground, const short& _background);

    void Draw(const Drawer& drawer, const IVector2& offset) const override;
};

