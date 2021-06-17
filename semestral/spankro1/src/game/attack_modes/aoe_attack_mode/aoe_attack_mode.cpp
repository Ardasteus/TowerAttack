#include "aoe_attack_mode.h"
#include "core/game_manager/game_manager.h"
#include "game/attacker_entity/attacker_entity.h"

vector<shared_ptr<AttackerEntity>> AoEAttackMode::GetAttackersToDamage(const IVector2& position, const int& radius, GameManager& game_manager) const
{
    vector<shared_ptr<AttackerEntity>> to_attack;
    vector<shared_ptr<GameObject>> in_radius = game_manager.GetEntitiesInSquare(position, radius);
    for(const auto& obj : in_radius)
    {
        shared_ptr<AttackerEntity> attacker = dynamic_pointer_cast<AttackerEntity>(obj);
        if(attacker != nullptr)
            to_attack.push_back(attacker);
    }
    return to_attack;
}