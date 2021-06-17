#pragma once

using namespace std;

#include "game/attack_modes/aoe_attack_mode/aoe_attack_mode.h"
#include "game/attack_modes/closest_attack_mode/closest_attack_mode.h"
#include "game/attack_modes/furthest_attack_mode/furthest_attack_mode.h"
#include <memory>

class AttackModeFactory
{
public:
    shared_ptr<AttackMode> CreateAttackMode(const string& name);
};