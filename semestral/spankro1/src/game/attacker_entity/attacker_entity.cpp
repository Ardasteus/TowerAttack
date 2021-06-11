#include "attacker_entity.h"
#include "core/game_manager/game_manager.h"

AttackerEntity::AttackerEntity(const IVector2& _position, string _name, AttackerTemplate a_template)
: GameObject(_name, _position, a_template.draw_character, a_template.foregroundColor, a_template.backgroundColor)
{
    onDestroy = nullptr;
    cost_to_spawn = a_template.cost;
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
    TileGameObjectPair current = game_manager.GetGameObjectAtPosition(position);
    if(current.tile_type == TileType::End)
    {
        onEnd();
        onDestroy(position);
    }
    vector<TileGameObjectPair> in_radius = game_manager.GetGameObjectsInSquare(position, 1);
    for(auto obj : in_radius)
    {
        AttackerEntity* attacker = dynamic_cast<AttackerEntity*>(obj.game_object.get());
        if((obj.tile_type == TileType::Path && attacker == nullptr &&
            obj.game_object->GetPosition() != position && obj.game_object->GetPosition() != previous_position)
            || obj.tile_type == TileType::End)
        {
            game_manager.MoveEntity(position, obj.game_object->GetPosition());
            previous_position = position;
            position = obj.game_object->GetPosition();
            return;
        }
    }
}

int AttackerEntity::GetCost() const
{
    return cost_to_spawn;
}

void AttackerEntity::ApplyDamage(int damage)
{
    current_health -= damage;
    if(current_health <= 0)
        onDestroy(position);
}

void AttackerEntity::SetOnEndCallback(function<void()> func)
{
    onEnd = func;
}