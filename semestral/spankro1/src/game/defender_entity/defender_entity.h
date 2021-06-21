#pragma once

using namespace std;

#include "math/vector/ivector2.h"
#include "game/game_object/game_object.h"
#include "game/defender_entity/defender_template.h"
#include "game/attacker_entity/attacker_entity.h"
#include "core/tile_game_object_pair/tile_game_object_pair.h"
#include "game/attack_modes/attack_mode/attack_mode.h"
#include "game/attack_modes/attack_mode_factory/attack_mode_factory.h"
#include "enums/damage_type.h"

/**
 * This entity represents the AI controlled side of this game.
 */
class DefenderEntity : public GameObject
{
protected:
    /**
     * Attack radius of this entity
     */
    int attack_radius;

    /**
     * Damage output of this entity
     */
    int attack_damage;

    /**
     * Price to be paid when this entity is spawned
     */
    int cost_to_spawn;

    /**
     * Attack mode strategy
     */
    shared_ptr<AttackMode> attack_mode;

    /**
     * Damage type of this entity
     */
    DamageType attack_type;
public:
    /**
     * Creates an entity with name and position using specificed template
     * 
     * @param _position Position of the entity
     * @param _name Name of the entity
     * @param d_template DefenderTemplate to be used
     */
    DefenderEntity(const IVector2& _position, const string& _name, const DefenderTemplate& d_template);

    /**
     * Draws the DefenderEntity. Should be only called once as these entites do not move.
     * 
     * @param drawer Drawer instance to be used
     * @param offset Offset position to be used
     */
    void Draw(const Drawer& drawer, const IVector2& offset) override;

    /**
     * Updates the entity. Tries to attack AttackerEntity objects in its range
     * 
     * @param game_manager GameManager instance to be used
     */
    void Update(GameManager& game_manager) override;
};