#pragma once

class WindowBorder
{
private:
    char leftSide;
    char rightSide;
    char topSide;
    char bottomSide;
    char topLeftCorner;
    char topRightCorner;
    char bottomLeftCorner;
    char bottomRightCorner;
public:
    WindowBorder();
    WindowBorder(const char& leftside, const char& rightside, 
                    const char& topside, const char& bottomside, 
                    const char& topleft, const char& topright, 
                    const char& bottomleft, const char& bottomright);
    WindowBorder(const WindowBorder& other);
    ~WindowBorder();

    WindowBorder& operator=(const WindowBorder& other);
};
