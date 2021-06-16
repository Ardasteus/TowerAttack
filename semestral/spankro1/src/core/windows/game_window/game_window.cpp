#include "game_window.h"
#include "core/game_manager/game_manager.h"

GameWindow::GameWindow()
: GUIWindow("GameWindow", 62, 22, IVector2(0,0)),
stats_window(62, 3, IVector2(0,22)),
attacker_picker(22, 25, IVector2(63,0))
{

}

GameWindow::~GameWindow()
{

}

void GameWindow::HandleInput(const int& key, GameManager& game_manager)
{
    attacker_picker.HandleInput(key, game_manager);
}

void GameWindow::Draw(const Drawer& drawer, const IVector2& offset)
{
    GUIWindow::Draw(drawer, offset);
    stats_window.Draw(drawer, offset);
    attacker_picker.Draw(drawer, offset);
}

void GameWindow::Initialize()
{
    GUIWindow::Initialize();
    stats_window.Initialize();
    attacker_picker.Initialize();
}

void GameWindow::Initialize(GameManager& game_manager)
{
    stats_window.Initialize(game_manager);
    attacker_picker.Initialize(game_manager);
}