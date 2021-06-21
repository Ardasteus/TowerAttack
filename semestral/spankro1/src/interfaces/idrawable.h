#pragma once

using namespace std;

#include "graphics/drawer/drawer.h"

/**
 * Interface that objects that draw have to implement.
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