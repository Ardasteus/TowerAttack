#pragma once

#include "ui/controls/gui_object/gui_object.h"
#include <string>

/**
 * Basic UI control that displays text.
 */
class Label : public GUIObject
{
protected:
    /**
     * Text to be displayed
     */
    std::string text;
public:
    /**
     * Constructor
     * 
     * Height is always 1
     * 
     * @param name Name of the Label
     * @param caption Caption of the Label
     * @param position Position of the Label
     * @param width Width of the Label
     * @param fg Foreground color of the Label
     * @param bg Background color of the Label
     */
    Label(const std::string& name, const std::string& caption, const IVector2& position, const int& width, const short& fg, const short& bg);

    /**
     * Draws the label.
     * 
     * If the text is wider than the actual width of the label, the text gets trimmed.
     * 
     * @param drawer Drawer instance to be used
     * @param offset Offset position to be used
     */
    void Draw(const Drawer& drawer, const IVector2& offset) override;

    /**
     * Sets new text to be displayed.
     * 
     * @param new_text New text to be displayed
     */
    void UpdateText(const string& new_text);
};

