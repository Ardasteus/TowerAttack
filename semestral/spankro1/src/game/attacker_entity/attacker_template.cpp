#include "attacker_template.h"

AttackerTemplate::AttackerTemplate(string _name, int hp, short fgc, short bgc, char dc)
{
    name = _name;
    health = hp;
    foregroundColor = fgc;
    backgroundColor = bgc;
    draw_character = dc;
}