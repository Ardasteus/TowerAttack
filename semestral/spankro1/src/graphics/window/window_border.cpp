#include "window_border.h"

WindowBorder::WindowBorder()
{
    leftSide = '|';
    rightSide = '|';
    topSide = '-';
    bottomSide = '-';
    topLeftCorner = '+';
    topRightCorner = '+';
    bottomLeftCorner = '+';
    bottomRightCorner = '+';
}

WindowBorder::WindowBorder(const char& leftside, const char& rightside, 
                    const char& topside, const char& bottomside, 
                    const char& topleft, const char& topright, 
                    const char& bottomleft, const char& bottomright)
{
    leftSide = leftside;
    rightSide = rightside;
    topSide = topside;
    bottomSide = bottomside;
    topLeftCorner = topleft;
    topRightCorner = topright;
    bottomLeftCorner = bottomleft;
    bottomRightCorner = bottomright;
}

WindowBorder::WindowBorder(const WindowBorder& other)
{
    leftSide = other.leftSide;
    rightSide = other.rightSide;
    topSide = other.topSide;
    bottomSide = other.bottomSide;
    topLeftCorner = other.topLeftCorner;
    topRightCorner = other.topRightCorner;
    bottomLeftCorner = other.bottomLeftCorner;
    bottomRightCorner = other.bottomRightCorner;
}

WindowBorder::~WindowBorder()
{
}

WindowBorder& WindowBorder::operator=(const WindowBorder& other)
{
    leftSide = other.leftSide;
    rightSide = other.rightSide;
    topSide = other.topSide;
    bottomSide = other.bottomSide;
    topLeftCorner = other.topLeftCorner;
    topRightCorner = other.topRightCorner;
    bottomLeftCorner = other.bottomLeftCorner;
    bottomRightCorner = other.bottomRightCorner;
    return *this;
}