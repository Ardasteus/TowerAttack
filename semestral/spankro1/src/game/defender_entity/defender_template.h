#pragma once

using namespace std;

#include <string>

/**
 * Template to create DefenderEntity objects with given parameters
 */
class DefenderTemplate
{
public:
    /**
     * Name of the template
     */
    string name;

    /**
     * Attack radius of DefenderEntity created using this template
     */
    int attack_radius;

    /**
     * Attack damage of DefenderEntity created using this template
     */
    int attack_damage;

    /**
     * Foreground color of DefenderEntity created using this template
     */
    short foreground_color;

    /**
     * Background color of DefenderEntity created using this template
     */
    short background_color;

    /**
     * Icon of DefenderEntity created using this template
     */
    char draw_character;

    /**
     * How many times has this template been used
     */
    int count;

    /**
     * Cost of DefenderEntity created using this template
     */
    int cost;

    /**
     * Attack mode of DefenderEntity created using this template
     * 
     * Closest - targets the closest AttackerEntity in range
     * Furthest - targets the furthest AttackerEntity in range
     * AoE - attacks every AttackerEntity in range
     */
    string attack_mode;

    /**
     * Attack type of DefenderEntity created using this template
     */
    string attack_type;

    /**
     * Default constructor
     */
    DefenderTemplate();

    /**
     * Creates custom template
     * 
     * @param _name Name of the template
     * @param fgc Foreground color of created DefenderEntity
     * @param bgc Background color of created DefenderEntity
     * @param dc Icon of created DefenderEntity
     * @param radius Radius of created DefenderEntity
     * @param damage Damage of created DefenderEntity
     * @param _cost Cost of created DefenderEntity
     * @param mode Attack mode of created DefenderEntity
     * @param type Attack type of created DefenderEntity
     */
    DefenderTemplate(string _name, short fgc, short bgc, char dc, int radius, int damage, int _cost, string mode, string type);
};