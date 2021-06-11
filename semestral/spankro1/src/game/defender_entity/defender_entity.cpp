#include "defender_entity.h"
#include "core/game_manager/game_manager.h"


using namespace std;

DefenderEntity::DefenderEntity(const IVector2& _position, string _name, DefenderTemplate d_template)
: GameObject(_name, _position, d_template.draw_character, d_template.foregroundColor, d_template.backgroundColor)
{
    onDestroy = nullptr;
    attack_damage = d_template.attack_damage;
    attack_radius = d_template.attack_radius;
}

void DefenderEntity::Draw(const Drawer& drawer, const IVector2& offset) const
{
    drawer.SetColor(foreground, background);
    drawer.DrawChar(draw_character, offset + position);
}

void DefenderEntity::Update(GameManager& game_manager)
{
    vector<TileGameObjectPair> in_radius = game_manager.GetGameObjectsInSquare(position, attack_radius);
    for(auto obj : in_radius)
    {
        AttackerEntity* attacker = dynamic_cast<AttackerEntity*>(obj.game_object.get());
        if(attacker != nullptr)
        {
            attacker->ApplyDamage(attack_damage);
        }
    }
}