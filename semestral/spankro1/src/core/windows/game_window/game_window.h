#pragma once

using namespace std;

#include "interfaces/iinitializable.h"
#include "game/attacker_entity/attacker_entity.h"
#include "game/defender_entity/defender_entity.h"
#include "ui/window/gui_window.h"
#include "ui/control_creator/control_creator.h"
#include "core/windows/game_stats_window/game_stats_window.h"
#include "core/windows/attacker_picker_window/attacker_picker_window.h"
#include "core/game_object_comparator/game_object_comparator.h"
#include "game/game_object/game_object.h"
#include "core/tile_game_object_pair/tile_game_object_pair.h"
#include "interfaces/iupdatable.h"
#include <memory>
#include <set>
#include <list>
#include <map>

const int GAME_WIDTH = 60;
const int GAME_HEIGHT = 20;

/**
 * Game window storing all the entites in game, drawing and updating them. Provides functions to manipulate the game.
 */
class GameWindow : public GUIWindow, public IInitializable, public IUpdatable
{
protected:
    /**
     * Stats window
     */
    GameStatsWindow stats_window;

    /**
     * Attacker picker window
     */
    AttackerPickerWindow attacker_picker;

    /**
     * 2D grid of all entites in the game
     */
    shared_ptr<GameObject> game_objects[GAME_WIDTH][GAME_HEIGHT];

    /**
     * 2D grid masking the entity grid, signifying tile types of given positions
     */
    TileType game_map_mask[GAME_WIDTH][GAME_HEIGHT];

    /**
     * Set of attackers
     */
    set<shared_ptr<GameObject>, GameObjectComparator> attackers;

    /**
     * Set of defenders
     */
    set<shared_ptr<GameObject>, GameObjectComparator> defenders;

    /**
     * Set of all path objects
     */
    list<shared_ptr<GameObject>> path_objects;

    /**
     * Vector of entites (attackers) to be removed
     */
    vector<shared_ptr<GameObject>> entities_to_remove;

    /**
     * Maps GameObject instances to given characters, used to simply map loading code
     */
    map<char, GameObject> map_game_objects;

    /**
     * Maps TileType to GameObject, simplifies removing of entities
     */
    map<TileType, GameObject> tile_game_objects;

    /**
     * Maps chars to TileTypes, used to simply map loading
     */
    map<char, TileType> char_tile_pair;

    /**
     * Location of spawner to spawn attackers from
     */
    IVector2 spawn_location;

    /**
     * Whether or not the window should fully redraw
     */
    bool full_redraw = true;
public:
    /**
     * Default constructor
     */
    GameWindow();

    /**
     * Default destructor
     */
    ~GameWindow();

    /**
     * Handles the input provided by the user
     * 
     * @param key Code of the key inputed
     * @param game_manager GameManager instance to be used
     */
    void HandleInput(const int& key, GameManager& game_manager) override;

    /**
     * Initialization function creating all the buttons etc.
     */
    void Initialize() override;

    /**
     * Draws the window and all other windows and entites
     * 
     * @param drawer Drawer instance to be used
     * @param offset Position to offset by
     */
    void Draw(const Drawer& drawer, const IVector2& offset);

    /**
     * Updates the entities
     * 
     * @param game_manager GameManager instance to be used
     */
    void Update(GameManager& game_manager) override;

    /**
     * Returns vector of GameObjects in a square of certain radius around given position
     * 
     * @param position Center of the square
     * @param radius Span of the lookup square
     * 
     * @return vector of found GameObject pointers
     */
    vector<shared_ptr<GameObject>> GetEntitiesInSquare(const IVector2& position, const int& radius);

    /**
     * Gets the GameObject at given position
     * 
     * @param position Position to look at
     * 
     * @return TileType/GameObject pair from given position
     */
    TileGameObjectPair GetGameObjectAtPosition(const IVector2& position);

    /**
     * Gets all path objects around position (in a cross)
     * 
     * @param position Position to look at
     * 
     * @return vector of pointers to found paths
     */
    vector<shared_ptr<GameObject>> GetPathsNearPosition(const IVector2& position);

    /**
     * Returns vector of all paths on current map
     * 
     * @return Vector of all path objects
     */
    vector<shared_ptr<GameObject>> GetAllPaths();

    /**
     * Tries to spawn an AttackerEntity of given AttackerTemplate on the spawn location
     * 
     * @param temp AttackerTemplate to use
     * 
     * @return pointer to newly created AttackerEntity or nullptr
     */
    shared_ptr<AttackerEntity> TrySpawnAttacker(const AttackerTemplate& temp);

    /**
     * Tries to spawn a DefenderEntity of given DefenderTemplate at given position
     * 
     * @param position Position to spawn the defender at
     * @param temp DefenderTemplate to use
     * 
     * @return pointer to newly created DefenderEntity or nullptr
     */
    shared_ptr<DefenderEntity> TrySpawnDefender(const IVector2& position, const DefenderTemplate& temp);

    /**
     * Tries to move an entity at given position to another position. Will fail if not moving an entity or moving onto an entity
     * 
     * @param position Position of the entity to move
     * @param move_to Position to move to
     * 
     * @return Whether or not the move went through
     */
    bool TryMoveEntity(const IVector2& position, const IVector2& move_to);

    /**
     * Deletes an object at given position
     * 
     * @param position Position of the object to delete
     */
    void DeleteObjectAtPosition(const IVector2& position);

    /**
     * Second initialization method that establishes connection to other game services
     * 
     * @param game_manager GameManager instance to use
     */
    void Initialize(GameManager& game_manager) override;

    /**
     * Loads a map form given file name
     * 
     * @param chosen_map File name to read from
     * 
     * @return Error message, empty if all went okay
     */
    string LoadMap(const string& chosen_map);

protected:
    /**
     * Returns true if GameObject at the position is a DefenderEntity or AttackerEntity
     * 
     * @param position Position to look az
     * 
     * @return true if entity, false otherwise
     */
    bool IsEntity(const IVector2& position);

    /**
     * Whether or not given position is in the grid
     * 
     * @param position Position to check
     * 
     * @return true if it is valid, false otherwise
     */
    bool IsPositionValid(const IVector2& position) const;
};