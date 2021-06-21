#pragma once

using namespace std;

#include "ui/window/gui_window.h"
#include "core/input_handler/input_handler.h"
#include "game/attacker_entity/attacker_entity.h"
#include "game/defender_entity/defender_entity.h"
#include "core/tile_game_object_pair/tile_game_object_pair.h"
#include "core/game_stats/game_stats.h"
#include "core/windows/game_stats_window/game_stats_window.h"
#include "utility/string_utilities.h"
#include "core/save_game/save_game.h"
#include "core/game_object_comparator/game_object_comparator.h"
#include "core/attacker_definition_handler/attacker_definition_handler.h"
#include "core/defender_definition_handler/defender_definition_handler.h"
#include "core/level_handler/level_handler.h"
#include "core/map_handler/map_handler.h"
#include "core/ai_agent/ai_agent.h"
#include "core/windows/main_menu_window/main_menu_window.h"
#include "interfaces/iinitializable.h"
#include "core/windows/game_window/game_window.h"
#include "core/windows/level_finished_window/level_finished_window.h"
#include "ncurses.h"
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

const int TOTAL_WIDTH = 100;
const int TOTAL_HEIGHT = 23;
const int WINDOW_BORDER = 2;
const int ATTACKER_UPDATE_TIME = 3;
const int DEFENDER_UPDATE_TIME = 15;
const int AI_UPDATE_TIME = 50;
const int STAT_UPDATE_TIME = 100;
const int DELTA_TIME = 33;

/**
 * Mega class that handles all communication between game logic and UI, loading data, etc.
 */
class GameManager
{
protected:
    map<string, shared_ptr<ILoadable>> loadable_objects;
    map<string, shared_ptr<IUpdatable>> updatable_services;
    map<string, shared_ptr<IInitializable>> init_objects;

    Drawer drawer;
    InputHandler input_handler;
    map<string, shared_ptr<GUIWindow>> gui_windows;
    shared_ptr<GUIWindow> current_window;
    bool game_running;
    bool force_redraw;
    bool change_level;
    bool exit_application = true;
    string error_message;
public:
    /**
     * Default constructor
     */
    GameManager();

    ~GameManager();
    void Run();
    vector<shared_ptr<GameObject>> GetEntitiesInSquare(const IVector2& position, const int& radius);
    TileGameObjectPair GetGameObjectAtPosition(const IVector2& position);
    vector<shared_ptr<GameObject>> GetPathsNearPosition(const IVector2& position);
    
    vector<DefenderTemplate> GetDefenderTemplates();
    DefenderTemplate GetRandomDefenderTemplate();
    AttackerTemplate GetAttackerTemplate(const string& name);
    vector<string> GetAttackerTemplateNames();
    vector<AttackerTemplate> GetAttackerTemplates();

    bool TryMoveEntity(const IVector2& position, const IVector2& move_to);
    void DeleteObjectAtPosition(const IVector2& position);

    void ChangeWindow(const string& window_name);
    bool TrySpawnDefender(const IVector2& position, const DefenderTemplate& temp);
    bool TrySpawnAttacker(const AttackerTemplate& temp);
    shared_ptr<GameStats> GetStats();
    shared_ptr<SaveGame> GetSaveGame();

    void LoadGame(const bool& new_game);
    void GoToNextLevel();
    bool LoadData();

    void CloseApplication();
    bool LoadRandomMap();

protected: 
    void Initialize();
 
    void Draw();

    void Update();

    void Dispose();
};  