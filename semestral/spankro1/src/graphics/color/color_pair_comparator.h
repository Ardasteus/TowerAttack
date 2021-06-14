#pragma once

#include "color_pair.h"

/**
 * Comparator used to sort color pairs
 */
struct ColorPairComparator
{
    /**
     * Compare function
     * 
     * Sorts by background and then foreground, this does not allow duplicates.
     * 
     * @param left First color pair to compare
     * @param right Second color pair to compare
     * @return Result of comparison
     */
    bool operator() (const ColorPair& left, const ColorPair& right)
    {
        if(left.GetForeground() == right.GetForeground())
            return left.GetBackground() < right.GetBackground();
        
        return left.GetForeground() < right.GetForeground();
    }
};