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

AttackerTemplate::AttackerTemplate(const string& _name, const int& hp, const int& _cost, const short& fgc, 
const short& bgc, const char& dc, const string& str, const string& weak)
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