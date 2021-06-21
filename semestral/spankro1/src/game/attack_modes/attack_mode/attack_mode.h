#pragma once

using namespace std;

#include "enums/attack_type.h"
#include <string>
#include <vector>
#include <memory>

class GameManager;
class AttackerEntity;
class IVector2;

/**
 * Attack mode class representing different attack modes of defenders. Decides how many and which attackers get attacked.
 */
class AttackMode
{
    /**
     * AttackType assigned to this AttackMode
     */
    AttackType type;
public:

    /**
     * Constructor that creates an AttackMode with assigned AttackType
     * 
     * @param _type AttackType to assign
     */
    AttackMode(const AttackType& _type)
    {
        type = _type;
    }

    /**
     * Gets the attackers to damage
     * 
     * @param position Origin of the lookup
     * @param radius Radius in which to search for attackers
     * @param game_manager GameManager instance to use
     * 
     * @return Vector of attackers to be hit
     */
    virtual vector<shared_ptr<AttackerEntity>> GetAttackersToDamage(const IVector2&, const int&, GameManager&) const = 0;
    
    /**
     * Returns the type of this AttackMode
     * 
     * @return Assigned AttackType
     */
    const AttackType& GetType() const
    {
        return type;
    }
};