#pragma once

#include "color_pair.h"

struct ColorPairComparator
{
    bool operator() (const ColorPair& left, const ColorPair& right);
};