#pragma once

#include <vector>

/**
 * Stores border characters for windows.
 */
class WindowBorder
{
protected:
    char left_side;
    char right_side;
    char top_side;
    char bottom_side;
    char top_left_corner;
    char top_right_corner;
    char bottom_left_corner;
    char bottom_right_corner;
public:

    /**
     * Default constructor
     * 
     * Default characters are:
     *      + for corners
     *      - for bottom and top side
     *      | for left and right side
     */
    WindowBorder();

    /**
     * Constructor to set custom border.
     * 
     * @param leftside Character to be used on the left wall
     * @param rightside Character to be used on the right wall
     * @param topside Character to be used on the top wall
     * @param bottomside Character to be used on the bottom wall
     * @param topleft Character to be used on the top left corner
     * @param topright Character to be used on the top right corner
     * @param bottomleft Character to be used on the bottom left corner
     * @param bottomright Character to be used on the top right corner
     */
    WindowBorder(const char& leftside, const char& rightside, 
                    const char& topside, const char& bottomside, 
                    const char& topleft, const char& topright, 
                    const char& bottomleft, const char& bottomright);

    /**
     * Copy constructor
     */
    WindowBorder(const WindowBorder& other);

    /**
     * Default destructor
     */
    ~WindowBorder();

    /**
     * Overloaded assigment operator.
     * 
     * Copies the values from different border onto this one.
     * 
     * @param other WindowBorder to copy from.
     * @return Reference to this WindowBorder
     */
    WindowBorder& operator=(const WindowBorder& other);

    /**
     * Returns a vector of with all characters used in the border
     * 
     * It is order by the order the characters are used in the constructor.
     * Left side first, bottom right corner last.
     * 
     * @return Vector of characters used in the border
     */
    std::vector<char> GetBorderCharacters() const;
};
