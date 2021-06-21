#include "attacker_entity.h"
#include "core/game_manager/game_manager.h"

AttackerEntity::AttackerEntity(const IVector2& _position, const string& _name, const AttackerTemplate& a_template)
: GameObject(_name, _position, a_template.draw_character, 
a_template.foreground_color, a_template.background_color, ATTACKER_UPDATE_TIME, GameObjectType::Attacker)
{
    ArmorTypeFactory factory;
    on_destroy = nullptr;
    cost_to_spawn = a_template.cost;
    max_health = a_template.health;
    current_health = a_template.health;
    armor_type = factory.GetArmorType(a_template.armor_type);
}

void AttackerEntity::Draw(const Drawer& drawer, const IVector2& offset)
{
    if(!is_active)
        return;

    if(has_been_hit)
    {
        current_hit_timer++;
        drawer.SetColor(COLOR_RED, background);
        if(current_hit_timer == hit_draw_timer)
            has_been_hit = false;
    }
    else
        drawer.SetColor(foreground, background);

    drawer.DrawChar(draw_character, offset + position);
}

void AttackerEntity::Update(GameManager& game_manager)
{
    if(!is_active)
        return;
    current_update_time++;
    if(current_update_time != update_time)
        return;

    current_update_time = 0;
    TileGameObjectPair current = game_manager.GetGameObjectAtPosition(position);
    if(current.tile_type == TileType::End)
    {
        is_active = false;
        on_end();
        on_destroy(position);
        return;
    }
    vector<shared_ptr<GameObject>> paths = game_manager.GetPathsNearPosition(position);
    for(const auto& path : paths)
    {
        IVector2 path_pos = path->GetPosition();
        if(path_pos != position && path_pos != previous_position && game_manager.TryMoveEntity(position, path_pos))
        {
            previous_position = position;
            position = path_pos;
            return;
        }
    }
}

int AttackerEntity::GetCost() const
{
    return cost_to_spawn;
}

void AttackerEntity::ApplyDamage(const int& damage, const DamageType& attack_type)
{
    int actual_damage = armor_type->GetDamageToApply(damage, attack_type);
        
    current_health -= actual_damage;
    has_been_hit = true;
    current_hit_timer = 0;
    if(current_health <= 0)
    {
        is_active = false;
        on_destroy(position);
    }
}

void AttackerEntity::SetOnEndCallback(const function<void()>& func)
{
    on_end = func;
}