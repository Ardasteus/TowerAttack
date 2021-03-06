#include "focusable_gui_object.h"

FocusableGUIObject::FocusableGUIObject(const string& _name, const IVector2& _position, const int& _width, const int& _height, 
    const short& fg, const short& bg, const short& ffg, const short& fbg)
: GUIObject(_name, _position, _width, _height, fg, bg)
{
    focused_foregound = ffg;
    focused_background = fbg;
    is_currently_focused = false;
}