#include "level_finished_window.h"
#include "core/game_manager/game_manager.h"

LevelFinishedWindow::LevelFinishedWindow()
: GUIWindow("LevelFinished", TOTAL_WIDTH + WINDOW_BORDER, TOTAL_HEIGHT + WINDOW_BORDER, IVector2(0,0))
{

}

void LevelFinishedWindow::Initialize()
{
    BaseWindow::Initialize();
    ControlCreator creator;
    shared_ptr<Label> info = creator.CreateLabel("Good job! Choose a permanent upgrade.", IVector2(0,0));
    shared_ptr<Button> gold = creator.CreateButton("Upgrade starting gold (150)", IVector2(0,1));
    gold->AddOnClickEvent([](GameManager& game_manager)
    {
        shared_ptr<SaveGame> save_game = game_manager.GetSaveGame();
        save_game->SetGold(save_game->GetGold() + 150);
        game_manager.GoToNextLevel();
    });
    shared_ptr<Button> income = creator.CreateButton("Upgrade income (10)", IVector2(0,2));
    income->AddOnClickEvent([](GameManager& game_manager)
    {
        shared_ptr<SaveGame> save_game = game_manager.GetSaveGame();
        save_game->SetIncome(save_game->GetIncome() + 10);
        game_manager.GoToNextLevel();
    });
    shared_ptr<Button> hp = creator.CreateButton("Upgrade attacker HP (100)", IVector2(0,3));
    hp->AddOnClickEvent([](GameManager& game_manager)
    {
        shared_ptr<SaveGame> save_game = game_manager.GetSaveGame();
        save_game->SetHP(save_game->GetHP() + 100);
        game_manager.GoToNextLevel();
    });
    AddElement(info);
    AddElement(gold);
    AddElement(income);
    AddElement(hp);
}