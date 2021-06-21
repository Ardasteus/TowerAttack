#pragma once

using namespace std;

#include <vector>
#include <functional>
#include "ui/controls/focusable_gui_object/focusable_gui_object.h"

class GameManager;

/**
 * UI component that executes a given action when Enter is pressed while it is focused.
 * 
 * Can execute multiple actions at once.
 */
class Button : public FocusableGUIObject
{
protected:
    /**
     * Text to be displayed
     */
    string caption;

    /**
     * Functions to be called when Buttons is activated
     */
    vector<function<void(GameManager&)>> on_click_functions;

public:
    /**
     * Constructor
     * 
     * Height is always 1
     * 
     * @param name Name of the Button
     * @param _caption Caption of the Button
     * @param position Position of the Button
     * @param width Width of the Button
     * @param fg Foreground color of the Button
     * @param bg Background color of the Button
     * @param ffg Foreground color of the Button when focused
     * @param fbg Background color of the Button when focused
     */
    Button(const std::string& name, const std::string& _caption, const IVector2& position, const int& width, 
    const short& fg, const short& bg, const short& ffg, const short& fbg);

    /**
     * Handles user input, if Enter is pressed the button is activated. GameManager is needed for the event being called.
     * 
     * @param key Code of the key that was pressed
     * @param game_manager GameManager instance to be used
     */
    void HandleInput(const int& key, GameManager& game_manager) override;

    /**
     * Draws the button.
     * 
     * If the caption is wider than the actual width, it gets trimmed.
     * 
     * @param drawer Drawer instance to use
     * @param offset Offset position to be used
     */
    void Draw(const Drawer& drawer, const IVector2& offset) override;

    /**
     * Adds a function to be called when this button is activated.
     * 
     * @param func Function to add
     */
    void AddOnClickEvent(function<void(GameManager&)> func);
};