#pragma once

using namespace std;

#include "game/game_object/game_object.h"
#include "attacker_template.h"
#include "core/tile_game_object_pair/tile_game_object_pair.h"
#include "game/armor_types/base_armor_type/base_armor_type.h"
#include "game/armor_types/armor_type_factory/armor_type_factory.h"
#include "enums/attack_type.h"
#include <memory>

/**
 * This entity represents the player controlled side of this game.
 */
class AttackerEntity : public GameObject
{
protected:
    /**
     * Maximum health of the entity
     */
    int max_health;

    /**
     * Current health of the entity
     */
    int current_health;

    /**
     * Cost of the entity
     */
    int cost_to_spawn;

    /**
     * Armor type of the attacker
     */
    shared_ptr<BaseArmorType> armor_type;

    /**
     * Callback when the entity reaches the End tile
     */
    function<void()> on_end;

    /**
     * Inidicates whether or not has the entity been damaged
     */
    mutable bool has_been_hit = false;

    /**
     * Draw timer limit for when the entity is hit
     */
    mutable int hit_draw_timer = 3;

    /**
     * Draw timer for when the entity is hit
     */
    mutable int current_hit_timer = 0;

    /**
     * Whether or not the entity should draw and update
     */
    bool is_active = true;
public:
    /**
     * Creates a new entity on given position, name and template.
     * 
     * @param _position Position of the entity
     * @param _name Name of the entity
     * @param a_template AttackerTemplate to be used
     */
    AttackerEntity(const IVector2& _position, const string& _name, const AttackerTemplate& a_template);

    /**
     * Draws the AttackerEntity.
     * 
     * @param drawer Drawer instance to be used
     * @param offset Offset position to be used
     */
    void Draw(const Drawer& drawer, const IVector2& offset) override;

    /**
     * Updates the entity. Tries to go forward on a map, onto another Path or End Tile.
     * 
     * @param game_manager GameManager instance to be used
     */
    void Update(GameManager& game_manager) override;

    /**
     * Applies damage to the entity, lowering current_health, if 0 calls on_destroy
     * 
     * If the entity is strong against this attack type, it will only take 0.75x the damage.
     * If it is weak against it, it will take 1.25x the damage.
     * 
     * @param damage Damage to be taken
     * @param attack_type Type of the dame
     */
    void ApplyDamage(const int& damage, const DamageType& attack_type);

    /**
     * Sets the on_destroy callback function
     * 
     * @param func Function to be set
     */
    void SetOnEndCallback(const function<void()>& func);

    /**
     * Returns the cost of the entity
     * 
     * @return Cost of the entity
     */
    int GetCost() const;
};