#include "physical_resistance_armor_type.h"

PhysicalResistanceArmorType::PhysicalResistanceArmorType()
: BaseArmorType(ArmorType::PhysicalResistance)
{
}

int PhysicalResistanceArmorType::GetDamageToApply(const int& damage, const DamageType& _type)
{

    switch (_type)
    {
        case DamageType::Physical:
            return damage * 0.75f;
            break;

        case DamageType::Magic:
            return damage * 1.25f;
            break;
        
        case DamageType::Chaos:
            return damage * 1.50f;
            break;

        default:
            return damage;
            break;
    }
}