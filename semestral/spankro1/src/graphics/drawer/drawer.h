#pragma once

#include "ncurses.h"
#include <string>
#include <memory>
#include <set>
#include <vector>
#include "graphics/window/window_wrapper.h"
#include "graphics/color/color_pair.h"
#include "graphics/color/color_pair_comparator.h"
#include "math/vector/ivector2.h"

class Drawer
{
private:
    mutable std::shared_ptr<WindowWrapper> currentWindow;
    mutable std::set<ColorPair, ColorPairComparator> colors;
    bool colorEnabled;

public:
    Drawer();
    ~Drawer();

    void Initialize();
    void Refresh();
    void Dispose();

    void SetWindow(const std::shared_ptr<WindowWrapper>& window) const;
    void SetColor(const short foreground, const short background) const;

    void DrawWindowBorder() const;
    void DrawChar(const char character, const IVector2 position) const;
    void DrawString(std::string text, const IVector2 position) const;
    WINDOW* GetWindow() const;
};
