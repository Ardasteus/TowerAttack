#pragma once

#include "game/attack_modes/attack_mode/attack_mode.h"

class ClosestAttackMode : public AttackMode
{
public:
    vector<shared_ptr<AttackerEntity>> GetAttackersToDamage(const IVector2& position, const int& radius, GameManager& game_manager) const override;
};