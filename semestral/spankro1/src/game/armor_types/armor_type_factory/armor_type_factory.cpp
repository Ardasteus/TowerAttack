#include "armor_type_factory.h"

shared_ptr<BaseArmorType> ArmorTypeFactory::GetArmorType(const ArmorType& type)
{
    switch (type)
    {
        case ArmorType::LimitedImmunity:
            return make_shared<LimitedImmunityArmorType>();
            break;
        
        case ArmorType::MagicalResistance:
            return make_shared<MagicalResistanceArmorType>();
            break;
        
        case ArmorType::PhysicalResistance:
            return make_shared<PhysicalResistanceArmorType>();
            break;
        
        default:
            return make_shared<NormalArmorType>();
            break;
    }
}