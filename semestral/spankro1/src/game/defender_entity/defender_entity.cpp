#include "defender_entity.h"
#include "core/game_manager/game_manager.h"


using namespace std;

DefenderEntity::DefenderEntity(const IVector2& _position, const string& _name, const DefenderTemplate& d_template)
: GameObject(_name, _position, d_template.draw_character, d_template.foreground_color, d_template.background_color, DEFENDER_UPDATE_TIME)
{
    on_destroy = nullptr;
    attack_damage = d_template.attack_damage;
    attack_radius = d_template.attack_radius;
    attack_mode = d_template.attack_mode;
    attack_type = d_template.attack_type;
}

void DefenderEntity::Draw(const Drawer& drawer, const IVector2& offset)
{
    drawer.SetColor(foreground, background);
    drawer.DrawChar(draw_character, offset + position);
}

void DefenderEntity::Update(GameManager& game_manager)
{
    if(++current_update_time != update_time)
        return;

    current_update_time = 0;
    
    for(const auto& attacker : attack_mode->GetAttackersToDamage(position, attack_radius, game_manager))
    {
        attacker->ApplyDamage(attack_damage, attack_type);
    }
}