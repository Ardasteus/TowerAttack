#pragma once

using namespace std;

#include "math/vector/ivector2.h"
#include "game/game_object/game_object.h"
#include "game/defender_entity/defender_template.h"
#include "game/attacker_entity/attacker_entity.h"

class DefenderEntity : public GameObject
{
protected:
    int attack_radius;
    int attack_damage;
public:
    DefenderEntity(const IVector2& _position, DefenderTemplate d_template);

    void Draw(const Drawer& drawer, const IVector2& offset) const override;
    void Update(GameManager& game_manager) override;
};