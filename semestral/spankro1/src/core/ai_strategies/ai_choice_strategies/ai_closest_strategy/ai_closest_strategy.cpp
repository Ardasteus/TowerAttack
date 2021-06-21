#include "ai_closest_strategy.h"
#include "core/game_manager/game_manager.h"

using namespace std;

const DefenderTemplate AIClosestStrategy::GetTemplateToUse(GameManager& game_manager)
{
    vector<DefenderTemplate> temp_templates = game_manager.GetDefenderTemplates();
    vector<DefenderTemplate> templates;
    for(const auto& temp : temp_templates)
        if(temp.attack_mode == AttackType::Closest)
            templates.push_back(temp);

    random_device rand;
    mt19937 rng(rand());
    uniform_int_distribution<int> rand_dist(0, templates.size() - 1);
    auto index = templates.begin();
    advance(index, rand_dist(rng));
    return *index;
}