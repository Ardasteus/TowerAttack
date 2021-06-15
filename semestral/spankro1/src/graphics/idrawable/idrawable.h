#pragma once

using namespace std;

#include "graphics/drawer/drawer.h"

/**
 * The base class for all objects that can draw.
 * 
 * This is a header only class
 */
class IDrawable
{
public:
    /**
     * Virtual draw method, used to tell the Drawer class instructions.
     * 
     * @param drawer Drawer instance to use
     * @param offset offset to be used when drawing
     */
    virtual void Draw(const Drawer& drawer, const IVector2& offset) = 0;
};