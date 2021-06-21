#pragma once

using namespace std;

#include "game/attack_modes/aoe_attack_mode/aoe_attack_mode.h"
#include "game/attack_modes/closest_attack_mode/closest_attack_mode.h"
#include "game/attack_modes/furthest_attack_mode/furthest_attack_mode.h"
#include <memory>

/**
 * Creates AttackMode instances. Moves the ugly if else chain to separate class
 */
class AttackModeFactory
{
public:

    /**
     * Returns an AttackMode based on AttackType
     * 
     * @param type Attack type to choose by
     * 
     * @return AttackMode
     */
    shared_ptr<AttackMode> CreateAttackMode(const AttackType type);
};