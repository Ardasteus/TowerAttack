#pragma once

using namespace std;

#include <string>
#include "graphics/drawable_object/drawable_object.h"
#include "math/vector/ivector2.h"

class GUIObject : public DrawableObject
{
protected:
    string name;
    IVector2 position;
    int width;
    int height;
    short foreground;
    short background;
public:
    GUIObject(const string& _name, const IVector2& _position, const int& _width, const int& _height, const short& fg, const short& bg);
    virtual ~GUIObject() {};

    int GetWidth() const;
};