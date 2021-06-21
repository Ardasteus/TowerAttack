#include "attacker_definition_handler.h"

bool AttackerDefinitionHandler::Load()
{
    attacker_templates.clear();
    fstream attacker_definitions;
    attacker_definitions.open("./assets/attacker_definitions", ios::in);
    if(attacker_definitions.is_open())
    {
        string line;
        getline(attacker_definitions, line);
        while(getline(attacker_definitions, line))
        {
            vector<string> values = StringUtils::SplitStringByDelimiter(line, ";");
            if(values.size() != 5)
            {
                attacker_definitions.close();
                error_message = "Attacker definitions failed to load: Invalid number of arguments, should be 5.";
                return false;
            }
            ArmorType type = ArmorType::Normal;
            if(values[4] == "LimitedImmunity")
                type = ArmorType::LimitedImmunity;
            else if(values[4] == "MagicalResist")
                type = ArmorType::MagicalResistance;
            else if(values[4] == "PhysicalResist")
                type = ArmorType::PhysicalResistance;

            AttackerTemplate new_template = AttackerTemplate(values[0], stoi(values[1]), stoi(values[2]), COLOR_CYAN, COLOR_BLACK, 
            values[3][0], type);
            attacker_templates[new_template.name] = new_template;
        }
        attacker_definitions.close();
        return true;
    }
    else
    {
        error_message = "Attacker definitions failed to load: File (./assets/attacker_definitions) could not be opened.";
        return false;
    }
}

const AttackerTemplate& AttackerDefinitionHandler::GetTemplate(const string& name)
{
    return attacker_templates[name];
}

vector<string> AttackerDefinitionHandler::GetTemplateNames() const
{
    vector<string> names;

    for(const auto& temp : attacker_templates)
        names.push_back(temp.first);

    return names;
}

vector<AttackerTemplate> AttackerDefinitionHandler::GetTemplates() const
{
    vector<AttackerTemplate> temps;

    for(const auto& temp : attacker_templates)
        temps.push_back(temp.second);

    return temps;
}

void AttackerDefinitionHandler::IncrementTemplateUse(const string& name)
{
    attacker_templates[name].count++;
}