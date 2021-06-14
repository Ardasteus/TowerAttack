#pragma once

using namespace std;

#include "game/game_object/game_object.h"
#include "ui/window/gui_window.h"
#include "ui/controls/gui_object/gui_object.h"
#include "core/input_handler/input_handler.h"
#include "game/attacker_entity/attacker_entity.h"
#include "game/defender_entity/defender_entity.h"
#include "ui/controls/button/button.h"
#include "core/enums/tile_type.h"
#include "core/tile_game_object_pair/tile_game_object_pair.h"
#include "core/game_stats/game_stats.h"
#include "core/game_stats_window/game_stats_window.h"
#include "utility/string_utilities.h"
#include "core/save_game/save_game.h"
#include "core/game_object_comparator/game_object_comparator.h"
#include <string>
#include <fstream>
#include <iterator>
#include <random>
#include <vector>
#include <map>
#include <memory>
#include <set>
#include <chrono>
#include <thread>
#include <iostream>

#define TOTAL_WIDTH 100
#define TOTAL_HEIGHT 23
#define GAME_WIDTH 60
#define GAME_HEIGHT 20
#define WINDOW_BORDER 2
#define ATTACKER_UPDATE_TIME 3
#define DEFENDER_UPDATE_TIME 5
#define AI_UPDATE_TIME 150
#define STAT_UPDATE_TIME 200
#define DELTA_TIME 33

class GameManager
{
private:
    BaseWindow game_window;
    GameStatsWindowHandler stats_window;

    shared_ptr<GameObject> game_objects[GAME_WIDTH][GAME_HEIGHT];
    int total_empty = 0;
    TileType game_map_mask[GAME_WIDTH][GAME_HEIGHT];
    vector<string> map_files;

    set<shared_ptr<GameObject>, GameObjectComparator> attackers;
    set<shared_ptr<GameObject>, GameObjectComparator> defenders;
    vector<GameObject> path_to_draw;
    vector<shared_ptr<GameObject>> defenders_to_draw;

    map<string, AttackerTemplate> attacker_templates;
    map<string, DefenderTemplate> defender_templates;
    IVector2 SpawnLocation;

    GameStats stats;

    SaveGame save_game;

    Drawer drawer;
    InputHandler input_handler;
    map<string, shared_ptr<GUIWindow>> gui_windows;
    shared_ptr<GUIWindow> current_window;
    bool game_running;
    bool force_redraw;
    bool change_level;
    int ai_update;
    int stat_update;

    bool exit_application = false;
    string error_message;
public:
    GameManager();

    void Run();

    vector<TileGameObjectPair> GetGameObjectsInSquare(IVector2 position, int radius) const;
    TileGameObjectPair GetGameObjectAtPosition(IVector2 position) const;
    vector<TileGameObjectPair> GetGameObjectsInCross(IVector2 position) const;
    
    void MoveEntity(IVector2 position, IVector2 move_to);

    void ChangeWindow(string window_type);

private: 
    shared_ptr<GUIWindow> AddGUIWindow(string name, int width, int height, IVector2 position);

    void Initialize();
    void Draw() const;
    void Update();
    void Dispose();

    void LoadAttackerDefinitions();
    void LoadDefenderDefinitions();
    void LoadMaps();
    void LoadRandomMap();

    bool TrySpawnAttacker(IVector2 position, string template_name);
    bool TrySpawnDefender(IVector2 position, string template_name);
    void DefenderAIUpdate();
    void StatUpdate();

    void GoToLevel(int level, bool new_game);
};  