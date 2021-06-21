#pragma once

#include "game/defender_entity/defender_template.h"

class GamenManager;

/**
 * Base class for all AI Defender choice strategies.
 */
class AIChoiceStrategy
{
public:

    /**
     * Decides what DefenderTemplate to use to spawn an entity
     * 
     * @param game_manager GameManager instance to be used
     * 
     * @return DefenderTemplate to be used
     */
    virtual const DefenderTemplate GetTemplateToUse(GameManager& game_manager) = 0;
};