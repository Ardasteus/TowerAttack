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
    attack_mode = "";
    attack_type = "";
}

DefenderTemplate::DefenderTemplate(string _name, short fgc, short bgc, char dc, int radius, int damage,
 int _cost, string mode, string type)
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
    attack_type = type;
}