#include "normal_armor_type.h"

NormalArmorType::NormalArmorType()
: BaseArmorType(ArmorType::Normal)
{
}

int NormalArmorType::GetDamageToApply(const int& damage, const DamageType& _type)
{
    switch (_type)
    {      
        case DamageType::Chaos:
            return damage * 1.75f;
            break;

        default:
            return damage;
            break;
    }
}