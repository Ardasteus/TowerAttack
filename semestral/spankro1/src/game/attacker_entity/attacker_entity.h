#pragma once

using namespace std;

#include "game/game_object/game_object.h"
#include "attacker_template.h"

class AttackerEntity : public GameObject
{
private:
    int max_health;
    int current_health;
public:
    AttackerEntity(const IVector2& _position, AttackerTemplate a_template);

    void Draw(const Drawer& drawer, const IVector2& offset) const override;
    void Update(GameManager& game_manager) override;
    void ApplyDamage(int damage);
};