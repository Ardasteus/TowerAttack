#pragma once

using namespace std;

#include "ncurses.h"
#include "interfaces/iloadable.h"
#include "game/attacker_entity/attacker_template.h"
#include "utility/string_utilities.h"
#include "game/armor_types/limited_immunity_armor_type/limited_immunity_armor_type.h"
#include "game/armor_types/magical_resistance_armor_type/magical_resistance_armor_type.h"
#include "game/armor_types/physical_resistance_armor_type/physical_resistance_armor_type.h"
#include <map>
#include <fstream>

/**
 * Handles the loading of attacker definitions
 */
class AttackerDefinitionHandler : public ILoadable
{
protected:
    /**
     * Map containing all the available attacker templates
     */
    map<string, AttackerTemplate> attacker_templates;
public:
    /**
     * Loads attacker definitions from a file
     * 
     * @return true if everything loaded correctly, false otherwise
     */
    bool Load() override;

    /**
     * Returns a template with given name
     * 
     * @param name Name of the template
     * 
     * @return Found template
     */
    const AttackerTemplate& GetTemplate(const string& name);

    /**
     * Increments the number of times template with given name was used
     * 
     * @param name Name of the template
     */
    void IncrementTemplateUse(const string& name);

    /**
     * Returns the vector of names of all templates
     * 
     * @return names of the templates
     */
    vector<string> GetTemplateNames() const;

    /**
     * Returns the actual templates
     * 
     * @return templates
     */
    vector<AttackerTemplate> GetTemplates() const;
};