#include "graphics/drawer/drawer.h"
#include "ui/window/gui_window.h"
#include "ui/controls/label/label.h"
#include "ui/controls/textbox/textbox.h"
#include <iostream>


int main()
{
    Drawer drawer;
    GUIWindow window1("Window", 20, 10, IVector2(0,0));
    GUIWindow window2("Window", 20, 10, IVector2(20,0));

    drawer.Initialize();
    window1.Initialize();
    window2.Initialize();

    window1.Draw(drawer);
    drawer.SetColor(COLOR_RED, COLOR_BLACK);
    drawer.DrawString("I am a window", IVector2(1,1));
    drawer.SetColor(COLOR_GREEN, COLOR_BLACK);
    drawer.DrawString("I am a window", IVector2(1,2));
    drawer.Refresh();

    WINDOW* temp = drawer.GetWindow();

    window2.AddElement(new Label("Label", "Hello There", IVector2(0,0), 10,
    COLOR_YELLOW, COLOR_BLUE));
    window2.AddElement(new Textbox("Text", "I am a textbox!", IVector2(0,1), 10,
    COLOR_YELLOW, COLOR_BLUE, COLOR_YELLOW, COLOR_BLUE));
    window2.Draw(drawer);
    drawer.Refresh();

    int key = -1;
    while ((key = wgetch(temp)) != 27) {
        if(key == KEY_END)
            break;
    }
    drawer.Dispose();

    return 0;
}