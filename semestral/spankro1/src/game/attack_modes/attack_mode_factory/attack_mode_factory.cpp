#include "attack_mode_factory.h"

shared_ptr<AttackMode> AttackModeFactory::CreateAttackMode(const AttackType& type)
{
    switch (type)
    {
        case AttackType::AoE:
            return make_shared<AoEAttackMode>();
            break;
    
        case AttackType::Closest:
            return make_shared<ClosestAttackMode>();
            break;

        case AttackType::Furthest:
            return make_shared<FurthestAttackMode>();
            break;

        default:
            return make_shared<ClosestAttackMode>();
            break;
    }
}