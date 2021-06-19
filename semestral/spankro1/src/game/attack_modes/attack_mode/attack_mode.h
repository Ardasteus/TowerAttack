#pragma once

using namespace std;

#include "enums/attack_type.h"
#include <string>
#include <vector>
#include <memory>

class GameManager;
class AttackerEntity;
class IVector2;

class AttackMode
{
    AttackType type;
public:
    AttackMode(const AttackType& _type)
    {
        type = _type;
    }

    virtual vector<shared_ptr<AttackerEntity>> GetAttackersToDamage(const IVector2& position, const int& radius, GameManager& game_manager) const = 0;
    
    const AttackType& GetType() const
    {
        return type;
    }
};