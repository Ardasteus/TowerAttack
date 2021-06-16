#include "attacker_entity.h"
#include "core/game_manager/game_manager.h"

AttackerEntity::AttackerEntity(const IVector2& _position, const string& _name, const AttackerTemplate& a_template)
: GameObject(_name, _position, a_template.draw_character, a_template.foreground_color, a_template.background_color, ATTACKER_UPDATE_TIME)
{
    on_destroy = nullptr;
    cost_to_spawn = a_template.cost;
    max_health = a_template.health;
    current_health = a_template.health;
    strength = a_template.strength;
    weakness = a_template.weakness;
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
    current_update_time++;
    if(current_update_time != update_time)
        return;

    current_update_time = 0;
    TileGameObjectPair current = game_manager.GetGameObjectAtPosition(position);
    if(current.tile_type == TileType::End)
    {
        on_end();
        on_destroy(position);
    }
    vector<TileGameObjectPair> in_radius = game_manager.GetGameObjectsInCross(position);
    for(const auto& obj : in_radius)
    {
        shared_ptr<AttackerEntity> attacker = dynamic_pointer_cast<AttackerEntity>(obj.game_object);
        if((obj.tile_type == TileType::Path && attacker == nullptr &&
            obj.game_object->GetPosition() != position && obj.game_object->GetPosition() != previous_position)
            || obj.tile_type == TileType::End)
        {
            on_move(position, obj.game_object->GetPosition());
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

void AttackerEntity::ApplyDamage(const int& damage, const string& attack_type)
{
    int actual_damage = damage;
    if(attack_type == strength)
        actual_damage *= 0.75f;
    else if(attack_type == weakness)
        actual_damage *= 1.25f;
        
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