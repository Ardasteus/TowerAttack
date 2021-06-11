#pragma once

using namespace std;

#include "game/game_object/game_object.h"
#include "attacker_template.h"
#include "core/tile_game_object_pair/tile_game_object_pair.h"

class AttackerEntity : public GameObject
{
private:
    int max_health;
    int current_health;
public:
    AttackerEntity(const IVector2& _position, string _name, AttackerTemplate a_template);

    void Draw(const Drawer& drawer, const IVector2& offset) const override;
    void Update(GameManager& game_manager) override;
    void ApplyDamage(int damage);
};