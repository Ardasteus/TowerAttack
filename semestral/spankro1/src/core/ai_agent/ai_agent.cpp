#include "ai_agent.h"
#include "core/game_manager/game_manager.h"

using namespace std;

void AIAgent::Update(GameManager& game_manager)
{
    current_update_time++;
    if(current_update_time != ai_update_time)
        return;

    current_update_time = 0;

    int tries = 5;
    bool spawned = false;
    int available_gold = game_manager.GetStats()->GetAIGold();
    random_device rand;
    mt19937 rng(rand());
    uniform_int_distribution<int> rand_x(0, GAME_WIDTH - 1);
    uniform_int_distribution<int> rand_y(0, GAME_HEIGHT - 1);
    while(!spawned && tries > 0)
    {
        DefenderTemplate def_template = game_manager.GetRandomDefenderTemplate();
        if(available_gold - def_template.cost < 0)
        {
            tries--;
            continue;
        }
        IVector2 rand_position(rand_x(rng), rand_y(rng));
        spawned = game_manager.TrySpawnDefender(rand_position, def_template);
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