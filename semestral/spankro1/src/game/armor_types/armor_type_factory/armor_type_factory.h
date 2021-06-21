#pragma once

using namespace std;

#include "game/armor_types/base_armor_type/base_armor_type.h"
#include "game/armor_types/limited_immunity_armor_type/limited_immunity_armor_type.h"
#include "game/armor_types/magical_resistance_armor_type/magical_resistance_armor_type.h"
#include "game/armor_types/normal_armor_type/normal_armor_type.h"
#include "game/armor_types/physical_resistance_armor_type/physical_resistance_armor_type.h"
#include <memory>

/**
 * Creates armor types from given ArmorType
 */
class ArmorTypeFactory
{
public:

    /**
     * Creates and returns new BaseArmorType
     * 
     * @param type BaseArmorType to create
     * 
     * @return new armor type
     */
    shared_ptr<BaseArmorType> GetArmorType(const ArmorType& type);
};