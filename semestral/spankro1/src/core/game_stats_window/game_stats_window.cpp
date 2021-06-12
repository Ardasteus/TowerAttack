#include "game_stats_window.h"

GameStatsWindowHandler::GameStatsWindowHandler(const int& width, const int& height, const IVector2& position)
{
    window = GUIWindow("Stats", width, height, position);
}

void GameStatsWindowHandler::Draw(const Drawer& drawer) const
{
    window.Draw(drawer);
}

void GameStatsWindowHandler::UpdateWindow(const GameStats& stats)
{
    labels["LevelValue"]->UpdateText(to_string(stats.current_level));
    labels["LivesValue"]->UpdateText(to_string(stats.lives));
    labels["GoldValue"]->UpdateText(to_string(stats.player_gold));
    labels["IncomeValue"]->UpdateText(to_string(stats.player_income));
}

void GameStatsWindowHandler::Initialize()
{
    window.Initialize();
    IVector2 position(0,0);
    ControlCreator creator;

    shared_ptr<Label> level_caption = creator.CreateLabel(" Level: ", position);
    position.SetX(position.GetX() + level_caption->GetWidth());
    labels["LevelCaption"] = level_caption;
    window.AddElement(level_caption);

    shared_ptr<Label> level_value = creator.CreateLabel("0", position, 2);
    position.SetX(position.GetX() + level_value->GetWidth());
    labels["LevelValue"] = level_value;
    window.AddElement(level_value);

    shared_ptr<Label> separator = creator.CreateLabel(" | ", position);
    position.SetX(position.GetX() + separator->GetWidth());
    window.AddElement(separator);

    shared_ptr<Label> lives_caption = creator.CreateLabel("Lives Left: ", position);
    position.SetX(position.GetX() + lives_caption->GetWidth());
    labels["LivesCaption"] = lives_caption;
    window.AddElement(lives_caption);

    shared_ptr<Label> lives_value = creator.CreateLabel("0", position, 3);
    position.SetX(position.GetX() + lives_value->GetWidth());
    labels["LivesValue"] = lives_value;
    window.AddElement(lives_value);

    separator = creator.CreateLabel(" | ", position);
    position.SetX(position.GetX() + separator->GetWidth());
    window.AddElement(separator);

    shared_ptr<Label> gold_caption = creator.CreateLabel("Gold: ", position);
    position.SetX(position.GetX() + gold_caption->GetWidth());
    labels["GoldCaption"] = gold_caption;
    window.AddElement(gold_caption);

    shared_ptr<Label> gold_value = creator.CreateLabel("0", position, 3);
    position.SetX(position.GetX() + gold_value->GetWidth());
    labels["GoldValue"] = gold_value;
    window.AddElement(gold_value);

    separator = creator.CreateLabel(" | ", position);
    position.SetX(position.GetX() + separator->GetWidth());
    window.AddElement(separator);

    shared_ptr<Label> income_caption = creator.CreateLabel("Income: ", position);
    position.SetX(position.GetX() + income_caption->GetWidth());
    labels["IncomeCaption"] = income_caption;
    window.AddElement(income_caption);

    shared_ptr<Label> income_value = creator.CreateLabel("0", position, 3);
    position.SetX(position.GetX() + income_value->GetWidth());
    labels["IncomeValue"] = income_value;
    window.AddElement(income_value);
}