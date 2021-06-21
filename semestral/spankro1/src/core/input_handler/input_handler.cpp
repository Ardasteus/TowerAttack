#include "input_handler.h"

InputHandler::InputHandler()
{
    input_window = nullptr;
}

InputHandler::~InputHandler()
{
    if(input_window != nullptr)
        delwin(input_window);
}

void InputHandler::Dispose()
{
    if(input_window != nullptr)
        delwin(input_window);
}

void InputHandler::Initialize()
{
    input_window = newwin(0, 0, 0, 0);
    nodelay(input_window, TRUE);
    keypad(input_window, true);
}

int InputHandler::HandleInput() const
{
    int key = wgetch(input_window);
    if(key == 27)
        return -1;
    return key;
}