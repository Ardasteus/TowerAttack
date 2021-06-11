#include "defender_template.h"

DefenderTemplate::DefenderTemplate()
{
    name = "Default";
    attack_radius = 0;
    attack_damage = 0;
    foregroundColor = 0;
    backgroundColor = 0;
    draw_character = ' ';
    count = 0;
}

DefenderTemplate::DefenderTemplate(string _name, short fgc, short bgc, char dc, int radius, int damage)
{
    name = _name;
    attack_radius = radius;
    attack_damage = damage;
    foregroundColor = fgc;
    backgroundColor = bgc;
    draw_character = dc;
    count = 0;
}