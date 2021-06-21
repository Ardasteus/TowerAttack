#include "magical_resistance_armor_type.h"

MagicalResistanceArmorType::MagicalResistanceArmorType()
: BaseArmorType(ArmorType::MagicalResistance)
{
}

int MagicalResistanceArmorType::GetDamageToApply(const int& damage, const DamageType& _type)
{

    switch (_type)
    {
        case DamageType::Physical:
            return damage * 1.250f;
            break;

        case DamageType::Magic:
            return damage * 0.75f;
            break;
        
        case DamageType::Chaos:
            return damage * 1.35f;
            break;

        default:
            return damage;
            break;
    }
}