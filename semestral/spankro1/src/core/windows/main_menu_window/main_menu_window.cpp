#include "main_menu_window.h"
#include "core/game_manager/game_manager.h"

MainMenuWindow::MainMenuWindow()
: GUIWindow("MainMenu", 100, 23, IVector2(0,0))
{

}

MainMenuWindow::~MainMenuWindow()
{

}

void MainMenuWindow::Initialize()
{
    BaseWindow::Initialize();
    ControlCreator creator;
    shared_ptr<Button> continue_game = creator.CreateButton("Continue Game", IVector2(0,0));
    continue_game->AddOnClickEvent([](GameManager& game_manager)
    {
        game_manager.LoadGame(false);
        game_manager.LoadRandomMap();
        game_manager.ChangeWindow("Game");
    });
    shared_ptr<Button> new_game = creator.CreateButton("New Game", IVector2(0,1));
    new_game->AddOnClickEvent([](GameManager& game_manager)
    {
        game_manager.LoadGame(true);
        game_manager.LoadRandomMap();
        game_manager.ChangeWindow("Game");
    });
    shared_ptr<Button> reload = creator.CreateButton("Reload Settings", IVector2(0,2));
    reload->AddOnClickEvent([](GameManager& game_manager)
    {
        game_manager.LoadData();
    });
    shared_ptr<Button> close = creator.CreateButton("Close", IVector2(0,3));
    close->AddOnClickEvent([](GameManager& game_manager)
    {
        game_manager.CloseApplication();
    });
    AddElement(continue_game);
    AddElement(new_game);
    AddElement(reload);
    AddElement(close);
}