#include "defender_template.h"

DefenderTemplate::DefenderTemplate(string _name, short fgc, short bgc, char dc, int radius, int damage)
{
    name = _name;
    attack_radius = radius;
    attack_damage = damage;
    foregroundColor = fgc;
    backgroundColor = bgc;
    draw_character = dc;
}