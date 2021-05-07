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

std::vector<char> WindowBorder::GetBorderCharacters() const
{
    std::vector<char> characters;
    characters.push_back(leftSide);
    characters.push_back(rightSide);
    characters.push_back(topSide);
    characters.push_back(bottomSide);
    characters.push_back(topLeftCorner);
    characters.push_back(topRightCorner);
    characters.push_back(bottomLeftCorner);
    characters.push_back(bottomRightCorner);

    return characters;
}