#pragma once

using namespace std;

#include <string>
#include "interfaces/idrawable.h"
#include "math/vector/ivector2.h"

/**
 * Base class for all UI objects
 */
class GUIObject : public IDrawable
{
protected:
    /**
     * Name of the UI object.
     */
    string name;

    /**
     * Position of the UI object
     */
    IVector2 position;

    /**
     * Width of an UI Object
     */
    int width;

    /**
     * Height of an UI Object
     */
    int height;

    /**
     * Foreground color
     */
    short foreground;

    /**
     * Background color
     */
    short background;
public:

    /**
     * Creates a new GUIObject with all required properties
     * 
     * @param _name Name of the UI object
     * @param _position Position of the UI object
     * @param _width Width of the UI object
     * @param _height Height of the UI object
     * @param fg Foreground color of the UI object
     * @param bg Background color of the UI object
     */
    GUIObject(const string& _name, const IVector2& _position, const int& _width, const int& _height, const short& fg, const short& bg);

    /**
     * Default destructor
     */
    virtual ~GUIObject() {};

    /**
     * Returns the width of the GUIObject
     * 
     * @return Width of the object
     */
    int GetWidth() const;
};