#pragma once

using namespace std;

#include "graphics/drawer/drawer.h"
#include "math/vector/ivector2.h"

/**
 * The base class for all objects that can draw.
 * 
 * This is a header only class
 */
class DrawableObject
{
public:
    /**
     * Default constructor.
     */
    DrawableObject() {};

    /**
     * Default virtual destructor.
     */
    virtual ~DrawableObject() {};

    /**
     * Virtual draw method, used to tell the Drawer class instructions.
     * 
     * @param drawer Drawer instance to use
     * @param offset offset to be used when drawing
     */
    virtual void Draw(const Drawer&, const IVector2&) const = 0;
};