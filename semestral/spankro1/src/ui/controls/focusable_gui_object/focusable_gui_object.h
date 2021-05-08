#pragma once

#include "ui/controls/gui_object/gui_object.h"

class FocusableGUIObject : public GUIObject
{
protected:
    bool isCurrentlyFocused;
    short focusedForegound;
    short focusedBackground;
public:
    FocusableGUIObject(const string& _name, const IVector2& _position, const int& _width, const int& _height, 
    const short& fg, const short& bg, const short& ffg, const short& fbg);
    virtual ~FocusableGUIObject() {};
    
    virtual void HandleInput(const int key) = 0;
};