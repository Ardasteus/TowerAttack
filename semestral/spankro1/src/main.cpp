#include "core/game_manager/game_manager.h"
#include <iostream>

void ButtonClick()
{
    throw invalid_argument("It called");
}

int main()
{
    GameManager game;
    game.Initialize();
    game.Run();
    return 0;
}