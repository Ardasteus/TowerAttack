#include "window_border.h"

WindowBorder::WindowBorder()
{
    left_side = '|';
    right_side = '|';
    top_side = '-';
    bottom_side = '-';
    top_left_corner = '+';
    top_right_corner = '+';
    bottom_left_corner = '+';
    bottom_right_corner = '+';
}

WindowBorder::WindowBorder(const char& leftside, const char& rightside, 
                    const char& topside, const char& bottomside, 
                    const char& topleft, const char& topright, 
                    const char& bottomleft, const char& bottomright)
{
    left_side = leftside;
    right_side = rightside;
    top_side = topside;
    bottom_side = bottomside;
    top_left_corner = topleft;
    top_right_corner = topright;
    bottom_left_corner = bottomleft;
    bottom_right_corner = bottomright;
}

WindowBorder::WindowBorder(const WindowBorder& other)
{
    left_side = other.left_side;
    right_side = other.right_side;
    top_side = other.top_side;
    bottom_side = other.bottom_side;
    top_left_corner = other.top_left_corner;
    top_right_corner = other.top_right_corner;
    bottom_left_corner = other.bottom_left_corner;
    bottom_right_corner = other.bottom_right_corner;
}

WindowBorder::~WindowBorder()
{
}

WindowBorder& WindowBorder::operator=(const WindowBorder& other)
{
    left_side = other.left_side;
    right_side = other.right_side;
    top_side = other.top_side;
    bottom_side = other.bottom_side;
    top_left_corner = other.top_left_corner;
    top_right_corner = other.top_right_corner;
    bottom_left_corner = other.bottom_left_corner;
    bottom_right_corner = other.bottom_right_corner;
    return *this;
}

std::vector<char> WindowBorder::GetBorderCharacters() const
{
    std::vector<char> characters;
    characters.push_back(left_side);
    characters.push_back(right_side);
    characters.push_back(top_side);
    characters.push_back(bottom_side);
    characters.push_back(top_left_corner);
    characters.push_back(top_right_corner);
    characters.push_back(bottom_left_corner);
    characters.push_back(bottom_right_corner);

    return characters;
}