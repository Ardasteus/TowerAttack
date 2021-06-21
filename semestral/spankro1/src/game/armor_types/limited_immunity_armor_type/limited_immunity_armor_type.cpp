#include "limited_immunity_armor_type.h"

LimitedImmunityArmorType::LimitedImmunityArmorType()
: BaseArmorType(ArmorType::LimitedImmunity)
{
    hits_left = 3;
}

int LimitedImmunityArmorType::GetDamageToApply(const int& damage, const DamageType& _type)
{
    if(hits_left > 0)
    {
        hits_left--;
        return 0;
    }

    switch (_type)
    {   
        case DamageType::Chaos:
            return damage * 1.50f;
            break;

        default:
            return damage;
            break;
    }
}