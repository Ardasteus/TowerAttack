#pragma once

#include "ncurses.h"

/**
 * Stores foreground/background color pair and its id.
 * 
 * Used in the drawer class to keep track of used color pairs
 */
class ColorPair
{
private:
    /**
     * Id of the color pair
     */
    short id;

    /**
     * Foreground color
     */
    short foreground;

    /**
     * Background color
     */
    short background;
public:
    /**
     * Constructor
     * 
     * @param _id Id of the color pair
     * @param fg Foreground color
     * @param bg Background color
     */
    ColorPair(const short& _id, const short& fg, const short& bg);

    /**
     * Default destructor
     */
    ~ColorPair();

    /**
     * Returns the id of color pair.
     * 
     * @return Id integer
     */
    int GetId() const;

    /**
     * Returns the foregound color of color pair.
     * 
     * @return Foreground integer
     */
    int GetForeground() const;

    /**
     * Gets the background color of color pair.
     * 
     * @return Background integer
     */
    int GetBackground() const;
};
