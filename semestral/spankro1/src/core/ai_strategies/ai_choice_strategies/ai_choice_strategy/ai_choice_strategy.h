#pragma once

#include "game/defender_entity/defender_template.h"

class GamenManager;

class AIChoiceStrategy
{
public:
    virtual const DefenderTemplate GetTemplateToUse(GameManager& game_manager) = 0;
};