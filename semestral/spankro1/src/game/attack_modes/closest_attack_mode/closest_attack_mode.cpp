#include "closest_attack_mode.h"
#include "core/game_manager/game_manager.h"
#include "game/attacker_entity/attacker_entity.h"

vector<shared_ptr<AttackerEntity>> ClosestAttackMode::GetAttackersToDamage(const IVector2& position, const int& radius, const GameManager& game_manager) const
{
    vector<shared_ptr<AttackerEntity>> to_attack;
    vector<TileGameObjectPair> in_radius = game_manager.GetGameObjectsInSquare(position, radius);

    shared_ptr<AttackerEntity> closest = nullptr;
    double distance = GAME_WIDTH * GAME_HEIGHT;
    for(const auto& obj : in_radius)
    {
        shared_ptr<AttackerEntity> attacker = dynamic_pointer_cast<AttackerEntity>(obj.game_object);
        if(attacker != nullptr)
        {
            double attack_distance = IVector2::GetDistance(position, attacker->GetPosition());
            if(attack_distance < distance)
            {
                distance = attack_distance;
                closest = attacker;
            }
        }
    }

    if(closest != nullptr)
        to_attack.push_back(closest);

    return to_attack;
}