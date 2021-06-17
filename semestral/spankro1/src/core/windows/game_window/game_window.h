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

class GameWindow : public GUIWindow, public IInitializable, public IUpdatable
{
protected:
    GameStatsWindow stats_window;
    AttackerPickerWindow attacker_picker;

    shared_ptr<GameObject> game_objects[GAME_WIDTH][GAME_HEIGHT];
    TileType game_map_mask[GAME_WIDTH][GAME_HEIGHT];

    set<shared_ptr<GameObject>, GameObjectComparator> attackers;
    set<shared_ptr<GameObject>, GameObjectComparator> defenders;
    list<shared_ptr<GameObject>> path_objects;
    vector<shared_ptr<GameObject>> entities_to_remove;

    map<char, GameObject> map_game_objects;
    map<TileType, GameObject> tile_game_objects;
    map<char, TileType> char_tile_pair;

    IVector2 spawn_location;

    bool full_redraw = true;
public:
    GameWindow();

    ~GameWindow();

    void HandleInput(const int& key, GameManager& game_manager) override;

    void Initialize() override;

    void Draw(const Drawer& drawer, const IVector2& offset);

    void Update(GameManager& game_manager) override;

    vector<shared_ptr<GameObject>> GetEntitiesInSquare(const IVector2& position, const int& radius);

    TileGameObjectPair GetGameObjectAtPosition(const IVector2& position);

    vector<shared_ptr<GameObject>> GetPathsNearPosition(const IVector2& position);

    shared_ptr<AttackerEntity> TrySpawnAttacker(const AttackerTemplate& temp);

    shared_ptr<DefenderEntity> TrySpawnDefender(const IVector2& position, const DefenderTemplate& temp);

    bool TryMoveEntity(const IVector2& position, const IVector2& move_to);

    void DeleteObjectAtPosition(const IVector2& position);

    void Initialize(GameManager& game_manager) override;

    string LoadMap(const string& chosen_map);

protected:
    bool IsEntity(const IVector2& position);

    bool IsPositionValid(const IVector2& position) const;
};