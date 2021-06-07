#include "defender_entity.h"

DefenderEntity::DefenderEntity(const IVector2& _position, DefenderTemplate d_template)
: GameObject(d_template.name, _position, d_template.draw_character, d_template.foregroundColor, d_template.backgroundColor)
{
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

}