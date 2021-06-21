#include "ai_agent.h"
#include "core/game_manager/game_manager.h"

using namespace std;

bool AIAgent::Load()
{
    fstream ai_settings;
    ai_settings.open("./assets/ai_settings", ios::in);
    if(ai_settings.is_open())
    {
        string line;
        getline(ai_settings, line);
        getline(ai_settings, line);
        vector<string> values = StringUtils::SplitStringByDelimiter(line, ";");
        if(values.size() != 3)
        {
            ai_settings.close();
            error_message = "AI Settings failed to load: wrong amount of parameters. Should be 3";
            return false; 
        }
        ai_update_time = stoi(values[0]);
        current_update_time = 0;
        string choice = values[1];
        if(choice == "AoE")
            defender_choice_strategy = make_unique<AIAoeStrategy>();
        else if(choice == "Furthest")
            defender_choice_strategy = make_unique<AIFurthestStrategy>();
        else if(choice == "Closest")
            defender_choice_strategy = make_unique<AIClosestStrategy>();
        else if(choice == "Cyclic")
            defender_choice_strategy = make_unique<AICyclicStrategy>();
        else
            defender_choice_strategy = make_unique<AIRandomStrategy>();
        
        choice = values[2];
        if(choice == "Path")
            placement_strategy = make_unique<AIPathRandomPlacementStrategy>();
        else
            placement_strategy = make_unique<AIRandomPlacementStrategy>();

        ai_settings.close();
        return true;
    }

    error_message = "AI Settings failed to load: file (./assets/ai_settings) failed to open.";
    return false;
}

void AIAgent::Update(GameManager& game_manager)
{
    current_update_time++;
    if(current_update_time != ai_update_time)
        return;

    current_update_time = 0;

    int tries = 3;
    bool spawned = false;
    int available_gold = game_manager.GetStats()->GetAIGold();
    random_device rand;
    mt19937 rng(rand());
    uniform_int_distribution<int> rand_x(0, GAME_WIDTH - 1);
    uniform_int_distribution<int> rand_y(0, GAME_HEIGHT - 1);
    while(!spawned && tries > 0)
    {
        DefenderTemplate def_template = defender_choice_strategy->GetTemplateToUse(game_manager);
        if(available_gold - def_template.cost < 0)
        {
            tries--;
            continue;
        }
        IVector2 position = placement_strategy->GetPositionToUse(game_manager);
        spawned = game_manager.TrySpawnDefender(position, def_template);
        if(spawned)
        {
            available_gold -= def_template.cost;
            game_manager.GetStats()->SetAIGold(available_gold);
            return;
        }
        tries--;
    }
}

void AIAgent::ResetTimer()
{
    current_update_time = 0;
}