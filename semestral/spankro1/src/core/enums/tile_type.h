#pragma once

/**
 * Enum that stores types of tiles, this helps the game recognize where things are and can be placed.
 * 
 * For example DefenderEntity objects can only be placed on an Empty tile, which then becomes a Tower tile.
 * AttackerEntity objects will only move from one Path tile to another and from Spawner to Path and from Path to End.
 */
enum TileType
{
    Empty,
    Unavailable,
    Tower,
    Path,
    Spawner,
    End
};