#pragma once

#include "ui/controls/focusable_gui_object/focusable_gui_object.h"

/**
 * UI component that emulates Textbox, user can type in letters and numbers and some other characters.
 */
class Textbox : public FocusableGUIObject
{
protected:
    /**
     * Current value of the textbox
     */
    std:: string value;
public:
    /**
     * Constructor
     * 
     * Height is always 1
     * 
     * @param name Name of the Textbox
     * @param initial_value Initial value of the textbox
     * @param position Position of the Textbox
     * @param width Width of the Textbox
     * @param fg Foreground color of the Textbox
     * @param bg Background color of the Textbox
     * @param ffg Foreground color of the Textbox when focused
     * @param fbg Background color of the Textbox when focused
     */
    Textbox(const std::string& name, const std::string& initial_value, const IVector2& position, const int& width, 
    const short& fg, const short& bg, const short& ffg, const short& fbg);

    /**
     * Handles user input, if supported key is pressed it will append that character to string, if backspace is pressed it deletes a character.
     * 
     * @param key Code of the key that was pressed
     * @param game_manager GameManager instance to be used
     */
    void HandleInput(const int& key, GameManager& game_manager) override;

    /**
     * Draws the textbox.
     * 
     * If the text is wider than actual width of the textbox, it gets trimmed.
     * 
     * @param drawer Drawer instance to be used
     * @param offset Offset position to be used
     */
    void Draw(const Drawer& drawer, const IVector2& offset) override;
};