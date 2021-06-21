#pragma once 

#include "enums/armor_type.h"
#include "enums/damage_type.h"

/**
 * Base class for all armor types
 */
class BaseArmorType
{
protected:
    /**
     * Given armor type to distinguish the armor type classes
     */
    ArmorType type;
public:
    /**
     * Constructor
     */
    BaseArmorType(const ArmorType& _type){ type = _type; }

    /**
     * Returns the damage to apply to the attacker
     * 
     * @param damage Original damage the defender wants to deal
     * @param _type Type of the damage
     * 
     * @return Returns the actual damage to deal
     */
    virtual int GetDamageToApply(const int&, const DamageType&) = 0;

    /**
     * Getter for ArmorType
     */
    const ArmorType& GetType() { return type; }
};