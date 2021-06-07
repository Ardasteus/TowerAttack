#include "attacker_entity.h"

AttackerEntity::AttackerEntity(const IVector2& _position, AttackerTemplate a_template)
: GameObject(a_template.name, _position, a_template.draw_character, a_template.foregroundColor, a_template.backgroundColor)
{
    max_health = a_template.health;
    current_health = a_template.health;
}

void AttackerEntity::Draw(const Drawer& drawer, const IVector2& offset) const
{
    drawer.SetColor(foreground, background);
    drawer.DrawChar(draw_character, offset + position);
}

void AttackerEntity::Update(GameManager& game_manager)
{

}