#include "color_pair.h"

ColorPair::ColorPair(const short& _id, const short& fg, const short& bg)
{
    id = _id;
    foreground = fg;
    background = bg;
}

ColorPair::~ColorPair()
{

}

int ColorPair::GetId() const
{
    return id;
}

int ColorPair::GetForeground() const
{
    return foreground;
}

int ColorPair::GetBackground() const
{
    return background;
}