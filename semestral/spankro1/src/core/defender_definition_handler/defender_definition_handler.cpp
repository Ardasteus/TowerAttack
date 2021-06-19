#include "defender_definition_handler.h"

DefenderDefinitionHandler::DefenderDefinitionHandler()
{
    
}

bool DefenderDefinitionHandler::Load()
{
    defender_templates.clear();
    fstream defender_definitions;
    defender_definitions.open("./assets/defender_definitions", ios::in);
    if(defender_definitions.is_open())
    {
        string line;
        getline(defender_definitions, line);
        while(getline(defender_definitions, line))
        {
            vector<string> values = StringUtils::SplitStringByDelimiter(line, ";");
            if(values.size() != 7)
            {
                defender_definitions.close();
                error_message = "Defender definitions failed to load: Invalid number of arguments, should be 7.";
                return false;
            }
            shared_ptr<AttackMode> mode = AttackModeFactory().CreateAttackMode(GetAttackTypeFromString(values[5]));
            DefenderTemplate new_template = DefenderTemplate(values[0], COLOR_YELLOW, COLOR_BLACK, 
            values[4][0], stoi(values[2]), stoi(values[1]), stoi(values[3]),
            mode, values[6]);
            defender_templates[new_template.name] = new_template;
        }
        defender_definitions.close();
        error_message = "";
        return true;
    }
    else
    {
        error_message = "Defender definitions failed to load: File (./assets/defender_definitions) could not be opened.";
        return false;
    }
}

const vector<DefenderTemplate> DefenderDefinitionHandler::GetTemplates()
{
    vector<DefenderTemplate> templates;
    for(const auto& temp : defender_templates)
        templates.push_back(temp.second);
    return templates;
}

const DefenderTemplate& DefenderDefinitionHandler::GetTemplate(const string& name)
{
    return defender_templates[name];
}

const DefenderTemplate& DefenderDefinitionHandler::GetRandomTemplate()
{
    random_device rand;
    mt19937 rng(rand());
    uniform_int_distribution<int> rand_dist(0, defender_templates.size() - 1);
    auto index = defender_templates.begin();
    advance(index, rand_dist(rng));
    return index->second;
}

const string& DefenderDefinitionHandler::GetError() const
{
    return error_message;
}

void DefenderDefinitionHandler::IncrementTemplateUse(const string& name)
{
    defender_templates[name].count++;
}

AttackType DefenderDefinitionHandler::GetAttackTypeFromString(const string& s)
{
    if(s == "AoE")
        return AttackType::AoE;
    if(s == "Furthest")
        return AttackType::Furthest;
    else
        return AttackType::Closest;
}