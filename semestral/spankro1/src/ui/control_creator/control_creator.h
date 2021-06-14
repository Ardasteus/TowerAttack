#pragma once

using namespace std;

#include "ui/controls/button/button.h"
#include "ui/controls/label/label.h"
#include "ui/controls/textbox/textbox.h"
#include <memory>

/**
 * Serves as a "factory" class that creates UI components with fully custom or some default parameters
 */
class ControlCreator
{
protected:
    short default_label_fg;
    short default_label_bg;
    short default_button_fg;
    short default_button_bg;
    short default_button_ffg;
    short default_button_fbg;
    short default_textbox_fg;
    short default_textbox_bg;
    short default_textbox_ffg;
    short default_textbox_fbg;
public:
    /**
     * Default constructor
     */
    ControlCreator();

    /**
     * Creates a new label with caption and position. The width is set to the width of the caption. Uses default colors defined in this class.
     * 
     * @param caption Caption of the Label
     * @param position Position of the Label
     * 
     * @return Pointer to the new Label
     */
    shared_ptr<Label> CreateLabel(string caption, IVector2 position);

    /**
     * Creates a new label with caption, position and width. Uses default colors defined in this class.
     * 
     * @param caption Caption of the Label
     * @param position Position of the Label
     * @param width Width of the Label
     * 
     * @return Pointer to the new Label
     */
    shared_ptr<Label> CreateLabel(string caption, IVector2 position, int width);

    /**
     * Creates a new label with caption, position, width and custom colors
     * 
     * @param caption Caption of the Label
     * @param position Position of the Label
     * @param width Width of the Label
     * @param fg_color Foreground color of the Label
     * @param bg_color Background color of the Label
     * 
     * @return Pointer to the new Label
     */
    shared_ptr<Label> CreateLabel(string caption, IVector2 position, int width, short fg_color, short bg_color);

    /**
     * Creates a new Button with caption and position. The width is set to the width of the caption. Uses default colors defined in this class.
     * 
     * @param caption Caption of the Button
     * @param position Position of the Button
     * 
     * @return Pointer to the new Button
     */
    shared_ptr<Button> CreateButton(string caption, IVector2 position);

    /**
     * Creates a new Button with caption, position and width. Uses default colors defined in this class.
     * 
     * @param caption Caption of the Button
     * @param position Position of the Button
     * @param width Width of the Button
     * 
     * @return Pointer to the new Button
     */
    shared_ptr<Button> CreateButton(string caption, IVector2 position, int width);

    /**
     * Creates a new Button with caption, position, width and custom colors
     * 
     * @param caption Caption of the Button
     * @param position Position of the Button
     * @param width Width of the Button
     * @param fg_color Foreground color of the Button
     * @param bg_color Background color of the Button
     * @param ffg_color Foreground color of the Button when focused
     * @param fbg_color Background color of the Button when focosed
     * 
     * @return Pointer to the new Button
     */
    shared_ptr<Button> CreateButton(string caption, IVector2 position, int width, short fg_color, short bg_color, short ffg_color, short fbg_color);

    /**
     * Creates a new Textbox with caption, position and no default value. Uses default colors.
     * 
     * @param position Position of the Textbox
     * @param width Width of the Textbox
     * 
     * @return Pointer to the new Textbox
     */
    shared_ptr<Textbox> CreateTextbox(IVector2 position, int width);

    /**
     * Creates a new Textbox with caption, position, custom colors and no default value.
     * 
     * @param position Position of the Textbox
     * @param width Width of the Textbox
     * @param fg_color Foreground color of the Textbox
     * @param bg_color Background color of the Textbox
     * @param ffg_color Foreground color of the Textbox when focused
     * @param fbg_color Background color of the Textbox when focosed
     * 
     * @return Pointer to the new Textbox
     */
    shared_ptr<Textbox> CreateTextbox(IVector2 position, int width, short fg_color, short bg_color, short ffg_color, short fbg_color);

    /**
     * Creates a new Textbox with caption, position and a default value. Uses default colors.
     * 
     * @param position Position of the Textbox
     * @param width Width of the Textbox
     * @param default_text Default value of the textbox
     * 
     * @return Pointer to the new Textbox
     */
    shared_ptr<Textbox> CreateTextbox(IVector2 position, int width, string default_text);

    /**
     * Creates a new Textbox with caption, position, custom colors and a default value.
     * 
     * @param position Position of the Textbox
     * @param width Width of the Textbox
     * @param default_text Default value of the textbox
     * @param fg_color Foreground color of the Textbox
     * @param bg_color Background color of the Textbox
     * @param ffg_color Foreground color of the Textbox when focused
     * @param fbg_color Background color of the Textbox when focosed
     * 
     * @return Pointer to the new Textbox
     */
    shared_ptr<Textbox> CreateTextbox(IVector2 position, int width, string default_text, short fg_color, short bg_color, short ffg_color, short fbg_color);
};