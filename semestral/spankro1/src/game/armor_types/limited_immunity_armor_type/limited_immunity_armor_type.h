#pragma once

#include "game/armor_types/base_armor_type/base_armor_type.h"

/**
 * Armor type that provides immunity to first few shots, after that takes more damage from Chaos only.
 */
class LimitedImmunityArmorType : public BaseArmorType
{
protected:
    /**
     * Immunity hits left
     */
    int hits_left;
public:
    /**
     * Default constuctor
     */
    LimitedImmunityArmorType();

    /**
     * Returns the damage to apply to the attacker
     * 
     * @param damage Original damage the defender wants to deal
     * @param _type Type of the damage
     * 
     * @return Returns the actual damage to deal
     */
    int GetDamageToApply(const int& damage, const DamageType& type);
};