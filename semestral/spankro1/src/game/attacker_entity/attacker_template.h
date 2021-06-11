#pragma once

using namespace std;

#include <string>

class AttackerTemplate
{
public:
    string name;
    int health;
    short foregroundColor;
    short backgroundColor;
    char draw_character;
    int count = 0;

    AttackerTemplate();
    AttackerTemplate(string _name, int hp, short fgc, short bgc, char dc);
};