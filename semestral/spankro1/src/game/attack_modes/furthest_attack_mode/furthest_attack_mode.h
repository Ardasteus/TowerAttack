#pragma once

#include "game/attack_modes/attack_mode/attack_mode.h"

/**
 * AttackMode that targets the furthest away attacker in an area
 */
class FurthestAttackMode : public AttackMode
{
public:

    /**
     * Default constructor
     */
    FurthestAttackMode();

    /**
     * Gets the attackers to damage
     * 
     * @param position Origin of the lookup
     * @param radius Radius in which to search for attackers
     * @param game_manager GameManager instance to use
     * 
     * @return Vector of attackers to be hit
     */
    vector<shared_ptr<AttackerEntity>> GetAttackersToDamage(const IVector2& position, const int& radius, GameManager& game_manager) const override;
};