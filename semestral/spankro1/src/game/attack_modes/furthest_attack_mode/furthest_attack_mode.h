#pragma once

#include "game/attack_modes/attack_mode/attack_mode.h"

class FurthestAttackMode : public AttackMode
{
public:
    FurthestAttackMode();
    vector<shared_ptr<AttackerEntity>> GetAttackersToDamage(const IVector2& position, const int& radius, GameManager& game_manager) const override;
};