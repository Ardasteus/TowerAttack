#include "attacker_template.h"

AttackerTemplate::AttackerTemplate()
{
    name = "Default";
    health = 0;
    cost = 0;
    foregroundColor = 0;
    backgroundColor = 0;
    draw_character = ' ';
    count = 0;
}

AttackerTemplate::AttackerTemplate(string _name, int hp, int _cost, short fgc, short bgc, char dc)
{
    name = _name;
    health = hp;
    cost = _cost;
    foregroundColor = fgc;
    backgroundColor = bgc;
    draw_character = dc;
    count = 0;
}