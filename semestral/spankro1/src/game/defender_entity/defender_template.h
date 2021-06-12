#pragma once

using namespace std;

#include <string>

class DefenderTemplate
{
public:
    string name;
    int attack_radius;
    int attack_damage;
    short foregroundColor;
    short backgroundColor;
    char draw_character;
    int count;
    int cost;
    string attack_mode;
    string attack_type;

    DefenderTemplate();
    DefenderTemplate(string _name, short fgc, short bgc, char dc, int radius, int damage, int _cost, string mode, string type);
};