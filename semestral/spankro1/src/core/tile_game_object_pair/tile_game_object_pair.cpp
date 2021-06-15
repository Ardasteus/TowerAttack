#include "tile_game_object_pair.h"

TileGameObjectPair::TileGameObjectPair(const TileType& _tile_type, const shared_ptr<GameObject>& _game_object)
{
    tile_type = _tile_type;
    game_object = _game_object;
}