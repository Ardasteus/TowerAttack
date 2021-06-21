#pragma once

#include "game/armor_types/base_armor_type/base_armor_type.h"

/**
 * Takes less damage from magic, but more from physical and slightly less from Chaos
 */
class MagicalResistanceArmorType : public BaseArmorType
{
public:
    /**
     * Default constructor
     */
    MagicalResistanceArmorType();

    /**
     * Returns the damage to apply to the attacker
     * 
     * @param damage Original damage the defender wants to deal
     * @param _type Type of the damage
     * 
     * @return Returns the actual damage to deal
     */
    int GetDamageToApply(const int& damage, const DamageType& _type);
};