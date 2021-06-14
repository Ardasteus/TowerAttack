#include "attacker_template.h"

AttackerTemplate::AttackerTemplate()
{
    name = "Default";
    health = 0;
    cost = 0;
    foreground_color = 0;
    background_color = 0;
    draw_character = ' ';
    count = 0;
    strength = "";
    weakness = "";
}

AttackerTemplate::AttackerTemplate(string _name, int hp, int _cost, short fgc, short bgc, char dc, string str, string weak)
{
    name = _name;
    health = hp;
    cost = _cost;
    foreground_color = fgc;
    background_color = bgc;
    draw_character = dc;
    count = 0;
    strength = str;
    weakness = weak;
}