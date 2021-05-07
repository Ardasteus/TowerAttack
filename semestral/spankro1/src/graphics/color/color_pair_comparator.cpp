#include "color_pair_comparator.h"

bool ColorPairComparator::operator() (const ColorPair& left, const ColorPair& right)
{
    if(left.GetForeground() == right.GetForeground())
        return left.GetBackground() < right.GetBackground();
    
    return left.GetForeground() < right.GetForeground();
}