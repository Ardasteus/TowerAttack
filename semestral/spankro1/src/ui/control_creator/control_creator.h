#pragma once

using namespace std;

#include "ui/controls/button/button.h"
#include "ui/controls/label/label.h"
#include "ui/controls/textbox/textbox.h"
#include <memory>

class ControlCreator
{
private:
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
    ControlCreator();

    shared_ptr<Label> CreateLabel(string caption, IVector2 position);
    shared_ptr<Label> CreateLabel(string caption, IVector2 position, int width);
    shared_ptr<Label> CreateLabel(string caption, IVector2 position, int width, short fg_color, short bg_color);

    shared_ptr<Button> CreateButton(string caption, IVector2 position);
    shared_ptr<Button> CreateButton(string caption, IVector2 position, int width);
    shared_ptr<Button> CreateButton(string caption, IVector2 position, int width, short fg_color, short bg_color, short ffg_color, short fbg_color);

    shared_ptr<Textbox> CreateTextbox(IVector2 position, int width);
    shared_ptr<Textbox> CreateTextbox(IVector2 position, int width, short fg_color, short bg_color, short ffg_color, short fbg_color);
    shared_ptr<Textbox> CreateTextbox(IVector2 position, int width, string default_text);
    shared_ptr<Textbox> CreateTextbox(IVector2 position, int width, string default_text, short fg_color, short bg_color, short ffg_color, short fbg_color);
};