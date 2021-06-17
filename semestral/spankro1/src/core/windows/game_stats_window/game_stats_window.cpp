#include "game_stats_window.h"
#include "core/game_manager/game_manager.h"

GameStatsWindow::GameStatsWindow(const int& width, const int& height, const IVector2& position)
: GUIWindow("Stats", width, height, position)
{
    
}

GameStatsWindow::~GameStatsWindow()
{
    labels.clear();
}

void GameStatsWindow::UpdateWindow(const GameStats& game_stats)
{
    labels["LevelValue"]->UpdateText(to_string(game_stats.GetLevel()));
    labels["LivesValue"]->UpdateText(to_string(game_stats.GetLives()));
    labels["GoldValue"]->UpdateText(to_string(game_stats.GetGold()));
    labels["IncomeValue"]->UpdateText(to_string(game_stats.GetIncome()));
}

void GameStatsWindow::Initialize(GameManager& game_manager)
{
    game_manager.GetStats()->SetOnUpdateCallback([&](GameStats& game_stats)
    {
        UpdateWindow(game_stats);
    });

    IVector2 position(0,0);
    ControlCreator creator;

    shared_ptr<Label> level_caption = creator.CreateLabel(" Level: ", position);
    position.SetX(position.GetX() + level_caption->GetWidth());
    labels["LevelCaption"] = level_caption;
    AddElement(level_caption);

    shared_ptr<Label> level_value = creator.CreateLabel("0", position, 2);
    position.SetX(position.GetX() + level_value->GetWidth());
    labels["LevelValue"] = level_value;
    AddElement(level_value);

    shared_ptr<Label> separator = creator.CreateLabel(" | ", position);
    position.SetX(position.GetX() + separator->GetWidth());
    AddElement(separator);

    shared_ptr<Label> lives_caption = creator.CreateLabel("Lives Left: ", position);
    position.SetX(position.GetX() + lives_caption->GetWidth());
    labels["LivesCaption"] = lives_caption;
    AddElement(lives_caption);

    shared_ptr<Label> lives_value = creator.CreateLabel("0", position, 3);
    position.SetX(position.GetX() + lives_value->GetWidth());
    labels["LivesValue"] = lives_value;
    AddElement(lives_value);

    separator = creator.CreateLabel(" | ", position);
    position.SetX(position.GetX() + separator->GetWidth());
    AddElement(separator);

    shared_ptr<Label> gold_caption = creator.CreateLabel("Gold: ", position);
    position.SetX(position.GetX() + gold_caption->GetWidth());
    labels["GoldCaption"] = gold_caption;
    AddElement(gold_caption);

    shared_ptr<Label> gold_value = creator.CreateLabel("0", position, 3);
    position.SetX(position.GetX() + gold_value->GetWidth());
    labels["GoldValue"] = gold_value;
    AddElement(gold_value);

    separator = creator.CreateLabel(" | ", position);
    position.SetX(position.GetX() + separator->GetWidth());
    AddElement(separator);

    shared_ptr<Label> income_caption = creator.CreateLabel("Income: ", position);
    position.SetX(position.GetX() + income_caption->GetWidth());
    labels["IncomeCaption"] = income_caption;
    AddElement(income_caption);

    shared_ptr<Label> income_value = creator.CreateLabel("0", position, 3);
    position.SetX(position.GetX() + income_value->GetWidth());
    labels["IncomeValue"] = income_value;
    AddElement(income_value);
}