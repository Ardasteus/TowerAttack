#pragma once

using namespace std;

#include "ncurses.h"
#include "game/attack_modes/attack_mode_factory/attack_mode_factory.h"
#include "interfaces/iloadable.h"
#include "game/defender_entity/defender_template.h"
#include "utility/string_utilities.h"
#include <map>
#include <fstream>
#include <random>

class DefenderDefinitionHandler : public ILoadable
{
protected:
    map<string, DefenderTemplate> defender_templates;
public:
    DefenderDefinitionHandler();
    bool Load() override;
    const string& GetError() const override;

    const DefenderTemplate& GetTemplate(const string& name);
    const DefenderTemplate& GetRandomTemplate();
    void IncrementTemplateUse(const string& name);
};