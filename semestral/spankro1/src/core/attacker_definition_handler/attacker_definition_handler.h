#pragma once

using namespace std;

#include "ncurses.h"
#include "interfaces/iloadable.h"
#include "game/attacker_entity/attacker_template.h"
#include "utility/string_utilities.h"
#include <map>
#include <fstream>

class AttackerDefinitionHandler : public ILoadable
{
protected:
    map<string, AttackerTemplate> attacker_templates;
public:
    bool Load() override;
    const string& GetError() const override;

    const AttackerTemplate& GetTemplate(const string& name);
};