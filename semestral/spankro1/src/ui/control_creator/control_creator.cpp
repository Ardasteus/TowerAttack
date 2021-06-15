#include "control_creator.h"

ControlCreator::ControlCreator()
{
     default_label_fg = COLOR_WHITE;
     default_label_bg = COLOR_BLACK;
     default_button_fg = COLOR_WHITE;
     default_button_bg = COLOR_BLACK;
     default_button_ffg = COLOR_BLUE;
     default_button_fbg = COLOR_BLACK;
     default_textbox_fg = COLOR_WHITE;
     default_textbox_bg = COLOR_BLACK;
     default_textbox_ffg = COLOR_CYAN;
     default_textbox_fbg = COLOR_BLACK;
}

shared_ptr<Label> ControlCreator::CreateLabel(const string& caption, const IVector2& position)
{
    int width = caption.size();
    return make_shared<Label>(Label("Label", caption, position, width, default_label_fg, default_label_bg));
}

shared_ptr<Label> ControlCreator::CreateLabel(const string& caption, const IVector2& position, const int& width)
{
    return make_shared<Label>(Label("Label", caption, position, width, default_label_fg, default_label_bg));
}

shared_ptr<Label> ControlCreator::CreateLabel(const string& caption, const IVector2& position, const int& width, const short& fg_color, const short& bg_color)
{
    return make_shared<Label>(Label("Label", caption, position, width, fg_color, bg_color));
}

shared_ptr<Button> ControlCreator::CreateButton(const string& caption, const IVector2& position)
{
    int width = caption.size();
    return make_shared<Button>(Button("Button", caption, position, width,
    default_button_fg, default_button_bg, default_button_ffg, default_button_fbg));
}

shared_ptr<Button> ControlCreator::CreateButton(const string& caption, const IVector2& position, const int& width)
{
    return make_shared<Button>(Button("Button", caption, position, width,
    default_button_fg, default_button_bg, default_button_ffg, default_button_fbg));
}

shared_ptr<Button> ControlCreator::CreateButton(const string& caption, const IVector2& position, const int& width, const short& fg_color, const short& bg_color, const short& ffg_color, const short& fbg_color)
{
    return make_shared<Button>(Button("Button", caption, position, width,
    fg_color, bg_color, ffg_color, fbg_color));
}

shared_ptr<Textbox> ControlCreator::CreateTextbox(const IVector2& position, const int& width)
{
    return make_shared<Textbox>(Textbox("Textbox", "", position, width, 
    default_textbox_fg, default_textbox_bg, default_button_ffg, default_button_fbg));
}

shared_ptr<Textbox> ControlCreator::CreateTextbox(const IVector2& position, const int& width, const short& fg_color, const short& bg_color, const short& ffg_color, const short& fbg_color)
{
    return make_shared<Textbox>(Textbox("Textbox", "", position, width, 
    fg_color, bg_color, ffg_color, fbg_color));
}

shared_ptr<Textbox> ControlCreator::CreateTextbox(const IVector2& position, const int& width, const string& default_text)
{
    return make_shared<Textbox>(Textbox("Textbox", default_text, position, width, 
    default_textbox_fg, default_textbox_bg, default_button_ffg, default_button_fbg));
}

shared_ptr<Textbox> ControlCreator::CreateTextbox(const IVector2& position, const int& width, const string& default_text, const short& fg_color, const short& bg_color, const short& ffg_color, const short& fbg_color)
{
    return make_shared<Textbox>(Textbox("Textbox", default_text, position, width, 
    fg_color, bg_color, ffg_color, fbg_color));
}