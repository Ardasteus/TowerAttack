#include "defender_template.h"

DefenderTemplate::DefenderTemplate()
{
    name = "Default";
    attack_radius = 0;
    attack_damage = 0;
    foreground_color = 0;
    background_color = 0;
    draw_character = ' ';
    count = 0;
    cost = 0;
    attack_mode = AttackType::Closest;
    attack_type = DamageType::Basic;
}

DefenderTemplate::DefenderTemplate(const string& _name, const short& fgc, const short& bgc, const char& dc, const int& radius, const int& damage, const int& _cost, 
    const AttackType& mode, const DamageType& damage_type)
{
    name = _name;
    attack_radius = radius;
    attack_damage = damage;
    foreground_color = fgc;
    background_color = bgc;
    draw_character = dc;
    count = 0;
    cost = _cost;
    attack_mode = mode;
    attack_type = damage_type;
}