#include "attack_mode_factory.h"

shared_ptr<AttackMode> AttackModeFactory::CreateAttackMode(const string& name)
{
    if(name == "AoE")
        return make_shared<AoEAttackMode>();
    else if(name == "Closest")
        return make_shared<ClosestAttackMode>();
    else
        return make_shared<FurthestAttackMode>();
}