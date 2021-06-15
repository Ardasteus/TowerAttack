#pragma once

using namespace std;

#include <string>

/**
 * Template to create AttackerEntity objects with given parameters
 */
class AttackerTemplate
{
public:
    /**
     * Name of the template
     */
    string name;

    /**
     * Health of AttackerEntity created using this template
     */
    int health;

    /**
     * Cost of AttackerEntity created using this template
     */
    int cost;

    /**
     * Foreground color of AttackerEntity created using this template
     */
    short foreground_color;

    /**
     * Background color of AttackerEntity created using this template
     */
    short background_color;

    /**
     * Icon of AttackerEntity created using this template
     */
    char draw_character;

    /**
     * How many times has this template been used
     */
    int count = 0;

    /**
     * Takes less damage from AttackerEntity attack type with same name
     */
    string strength;

    /**
     * Takes more damage from AttackerEntity attack type with same name
     */
    string weakness;

    /**
     * Default constructor
     */
    AttackerTemplate();

    /**
     * Creates custom template
     * 
     * @param _name Name of the template
     * @param hp Health of created AttackerEntity
     * @param _cost Cost of created AttackerEntity
     * @param fgc Foreground color of created AttackerEntity
     * @param bgc Background color of created AttackerEntity
     * @param dc Icon of created AttackerEntity
     * @param str Strength of created AttackerEntity
     * @param weak Weakness type of created AttackerEntity
     */
    AttackerTemplate(const string& _name, const int& hp, const int& _cost, const short& fgc, const short& bgc, const char& dc, const string& str, const string& weak);
};