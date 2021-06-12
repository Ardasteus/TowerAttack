#pragma once

using namespace std;

#include "graphics/drawer/drawer.h"
#include "math/vector/ivector2.h"

class DrawableObject
{
public:
    DrawableObject() {};
    virtual ~DrawableObject() {};

    virtual void Draw(const Drawer&, const IVector2&) const = 0;
};