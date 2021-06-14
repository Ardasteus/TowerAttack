#include "defender_entity.h"
#include "core/game_manager/game_manager.h"


using namespace std;

DefenderEntity::DefenderEntity(const IVector2& _position, string _name, DefenderTemplate d_template)
: GameObject(_name, _position, d_template.draw_character, d_template.foreground_color, d_template.background_color, DEFENDER_UPDATE_TIME)
{
    on_destroy = nullptr;
    attack_damage = d_template.attack_damage;
    attack_radius = d_template.attack_radius;
    attack_mode = d_template.attack_mode;
    attack_type = d_template.attack_type;
}

void DefenderEntity::Draw(const Drawer& drawer, const IVector2& offset) const
{
    drawer.SetColor(foreground, background);
    drawer.DrawChar(draw_character, offset + position);
}

void DefenderEntity::Update(GameManager& game_manager)
{
    current_update_time++;
    if(current_update_time != update_time)
        return;

    current_update_time = 0;
    vector<TileGameObjectPair> in_radius = game_manager.GetGameObjectsInSquare(position, attack_radius);
    if(attack_mode == "AoE")
    {
        for(auto obj : in_radius)
        {
            AttackerEntity* attacker = dynamic_cast<AttackerEntity*>(obj.game_object.get());
            if(attacker != nullptr)
            {
                attacker->ApplyDamage(attack_damage, attack_type);
            }
        }
    }
    else if(attack_mode == "Furthest")
    {
        AttackerEntity* to_attack = nullptr;
        double distance = 0;
        for(auto obj : in_radius)
        {
            AttackerEntity* attacker = dynamic_cast<AttackerEntity*>(obj.game_object.get());
            if(attacker != nullptr)
            {
                double attack_distance = IVector2::GetDistance(position, attacker->GetPosition());
                if(attack_distance > distance)
                {
                    distance = attack_distance;
                    to_attack = attacker;
                }
                attacker->ApplyDamage(attack_damage, attack_type);
            }
        }
        if(to_attack != nullptr)
            to_attack->ApplyDamage(attack_damage, attack_type);
    }
    else
    {
        AttackerEntity* to_attack = nullptr;
        double distance = GAME_WIDTH * GAME_HEIGHT;
        for(auto obj : in_radius)
        {
            AttackerEntity* attacker = dynamic_cast<AttackerEntity*>(obj.game_object.get());
            if(attacker != nullptr)
            {
                double attack_distance = IVector2::GetDistance(position, attacker->GetPosition());
                if(attack_distance < distance)
                {
                    distance = attack_distance;
                    to_attack = attacker;
                }
                attacker->ApplyDamage(attack_damage, attack_type);
            }
        }
        if(to_attack != nullptr)
            to_attack->ApplyDamage(attack_damage, attack_type);
    }
    
}