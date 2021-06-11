#pragma once

#include "core/enums/tile_type.h"
#include "game/game_object/game_object.h"

class TileGameObjectPair
{
public:
    TileGameObjectPair(const TileType _tile_type, shared_ptr<GameObject> _game_object);

    TileType tile_type;
    shared_ptr<GameObject> game_object;
};