#include "attacker_picker_window.h"
#include "core/game_manager/game_manager.h"

AttackerPickerWindow::AttackerPickerWindow(const int& width, const int& height, const IVector2& position)
: GUIWindow("AttackerPicker", width, height, position)
{

}

AttackerPickerWindow::~AttackerPickerWindow()
{

}

void AttackerPickerWindow::Initialize(GameManager& game_manager)
{
    ControlCreator creator;

    IVector2 button_pos(0,0);
    for(const auto& temp : game_manager.GetAttackerTemplates())
    {
        string temp_name = temp.name;
        shared_ptr<Button> spawn_button = creator.CreateButton("Spawn " + temp.name + " (" + to_string(temp.cost) + ")", button_pos);
        spawn_button->AddOnClickEvent([temp_name](GameManager& game_manager)
        {
            AttackerTemplate temp_to_use = game_manager.GetAttackerTemplate(temp_name);
            game_manager.TrySpawnAttacker(temp_to_use);
        });
        AddElement(spawn_button);
        button_pos += IVector2(0,1);
    }
    shared_ptr<Button> back_button = creator.CreateButton("Back to Main Menu", button_pos);
    back_button->AddOnClickEvent([](GameManager& game_manager)
    {
        game_manager.ChangeWindow("MainMenu");
    });
    AddElement(back_button);
}