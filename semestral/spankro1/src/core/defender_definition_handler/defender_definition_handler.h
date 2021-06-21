#pragma once

using namespace std;

#include "ncurses.h"
#include "game/attack_modes/attack_mode_factory/attack_mode_factory.h"
#include "interfaces/iloadable.h"
#include "game/defender_entity/defender_template.h"
#include "utility/string_utilities.h"
#include "enums/attack_type.h"
#include <map>
#include <fstream>
#include <random>

/**
 * Handles the laoding od defender definitions
 */
class DefenderDefinitionHandler : public ILoadable
{
protected:
    /**
     * Map containing available templates
     */
    map<string, DefenderTemplate> defender_templates;
public:
    /**
     * Loads defender definitions from a file
     * 
     * @return true if everything loaded correctly, false otherwise
     */
    bool Load() override;

    /**
     * Returns all templates available
     * 
     * @return vector containing all the templates
     */
    const vector<DefenderTemplate> GetTemplates();

    /**
     * Returns a specific template
     * 
     * @param name Name of the template
     * 
     * @return Template that was searched for
     */
    const DefenderTemplate& GetTemplate(const string& name);

    /**
     * Returns a random template
     * 
     * @return Random template
     */
    const DefenderTemplate& GetRandomTemplate();

    /**
     * Increments the number of times a given template has been used
     * 
     * @param name Name of the template
     */
    void IncrementTemplateUse(const string& name);
private:

    /**
     * Returns an attack type based on string
     * 
     * @param s Given string
     * 
     * @return Resulting attack type
     */
    AttackType GetAttackTypeFromString(const string& s);
};