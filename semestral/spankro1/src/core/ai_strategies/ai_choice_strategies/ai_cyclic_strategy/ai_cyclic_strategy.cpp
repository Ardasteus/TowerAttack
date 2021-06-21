#include "ai_cyclic_strategy.h"
#include "core/game_manager/game_manager.h"

const DefenderTemplate AICyclicStrategy::GetTemplateToUse(GameManager& game_manager)
{
    vector<DefenderTemplate> temp_templates = game_manager.GetDefenderTemplates();
    vector<DefenderTemplate> templates;
    for(const auto& temp : temp_templates)
        if(temp.attack_mode == current_type)
            templates.push_back(temp);

    random_device rand;
    mt19937 rng(rand());
    uniform_int_distribution<int> rand_dist(0, templates.size() - 1);
    auto index = templates.begin();
    advance(index, rand_dist(rng));

    switch (current_type)
    {
        case AttackType::Closest:
            current_type = AttackType::Furthest;
            break;

        case AttackType::Furthest:
            current_type = AttackType::AoE;
            break;

        case AttackType::AoE:
            current_type = AttackType::Closest;
            break;
        
        default:
            current_type = AttackType::Closest;
            break;
    }
    return *index;
}