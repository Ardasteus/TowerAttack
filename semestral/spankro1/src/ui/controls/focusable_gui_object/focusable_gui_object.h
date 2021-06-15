#pragma once

#include "ui/controls/gui_object/gui_object.h"
#include "ui/ifocusable/ifocusable.h"

/**
 * Base class for all focusable GUIObjects. They can recieve user input.
 */
class FocusableGUIObject : public GUIObject, public IFocusable
{
protected:
    /**
     * Foreground color to be used when this object is focused
     */
    short focused_foregound;

    /**
     * Background color to be used when this object is focused
     */
    short focused_background;
public:
    /**
     * Whether or not this object is currently focused.
     */
    bool is_currently_focused;

    /**
     * Constructor 
     * 
     * @param _name Name of the UI object
     * @param _position Position of the UI object
     * @param _width Width of the UI object
     * @param _height Height of the UI object
     * @param fg Foreground color of the UI object
     * @param bg Background color of the UI object
     * @param ffg Foreground color of the UI object when focused
     * @param fbg Background color of the UI object when focused
     */
    FocusableGUIObject(const string& _name, const IVector2& _position, const int& _width, const int& _height, 
    const short& fg, const short& bg, const short& ffg, const short& fbg);

    /**
     * Default destructor
     */
    virtual ~FocusableGUIObject() {};
};