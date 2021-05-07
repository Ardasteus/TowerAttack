#include "gui_object.h"

GUIObject::GUIObject(const string& _name, const IVector2& _position, const int& _width, const int& _height, const short& fg, const short& bg) : DrawableObject()
{
    name = _name;
    position = _position;
    width = _width;
    height = _height;
    foreground = fg;
    background = bg;
}

GUIObject::~GUIObject()
{
}