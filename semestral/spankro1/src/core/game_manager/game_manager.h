#pragma once

using namespace std;

#include "game/window/game_window.h"
#include "game/game_object/game_object.h"
#include "ui/window/gui_window.h"
#include "ui/controls/gui_object/gui_object.h"
#include "core/input_handler/input_handler.h"
#include "game/attacker_entity/attacker_entity.h"
#include "game/defender_entity/defender_entity.h"
#include "ui/controls/button/button.h"
#include "core/enums/tile_type.h"
#include "core/tile_game_object_pair/tile_game_object_pair.h"
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <set>
#include <chrono>
#include <thread>

#define GAME_WIDTH 20
#define GAME_HEIGHT 10

struct GameObjectComparator
{
    bool operator() (const shared_ptr<GameObject> left, const shared_ptr<GameObject> right)
    {
        return left->GetName() < right->GetName();
    }
};

class GameManager
{
private:
    shared_ptr<GameObject> game_objects[GAME_WIDTH][GAME_HEIGHT];
    TileType game_map_mask[GAME_WIDTH][GAME_HEIGHT];

    set<shared_ptr<GameObject>, GameObjectComparator> entities;

    map<string, AttackerTemplate> attacker_templates;
    map<string, DefenderTemplate> defender_templates;

    IVector2 SpawnLocation;

    Drawer drawer;
    list<shared_ptr<GameObject>> to_draw;

    InputHandler input_handler;
    BaseWindow game_window;
    map<string, shared_ptr<GUIWindow>> gui_windows;
    shared_ptr<GUIWindow> current_window;
    bool game_running = false;
    bool force_redraw = false;
    bool exit_application = false;
public:
    GameManager();

    void Run();

    vector<TileGameObjectPair> GetGameObjectsInSquare(IVector2 position, int radius) const;
    TileGameObjectPair GetGameObjectAtPosition(IVector2 position) const;
    
    void TrySpawnAttacker(IVector2 position, string template_name);
    void TrySpawnDefender(IVector2 position, string template_name);
    void MoveEntity(IVector2 position, IVector2 move_to);

    void ChangeWindow(string window_type);

private: 
    shared_ptr<GUIWindow> AddGUIWindow(string name, int width, int height, IVector2 position);

    void Initialize();
    void Draw() const;
    void Update();
    void Dispose();
};  