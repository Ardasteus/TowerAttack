#pragma once

#include "core/enums/tile_type.h"
#include "game/game_object/game_object.h"

/**
 * Used for grouping the GameObject and TileType instances from the same position
 * 
 * Acts as a return type for all "lookup" methods in GameManager
 */
class TileGameObjectPair
{
public:
    /**
     * Creates a pair from given TileType and GameObject pointer
     * 
     * @param _tile_type Tile type to use
     * @param _game_object GameObject pointer to use
     */
    TileGameObjectPair(const TileType& _tile_type, const shared_ptr<GameObject>& _game_object);

    /**
     * TileType
     */
    TileType tile_type;

    /**
     * GameObject
     */
    shared_ptr<GameObject> game_object;
};