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
 * Mega class that handles communication between services, acts as a proxy to GameWindow
 */
class GameManager
{
protected:
    /**
     * Loadable services
     */
    map<string, shared_ptr<ILoadable>> loadable_objects;

    /**
     * Updatable services
     */
    map<string, shared_ptr<IUpdatable>> updatable_services;

    /**
     * Objects to initialize
     */
    map<string, shared_ptr<IInitializable>> init_objects;

    /**
     * Drawer instance
     */
    Drawer drawer;

    /**
     * Input handler
     */
    InputHandler input_handler;

    /**
     * All window in the game
     */
    map<string, shared_ptr<GUIWindow>> gui_windows;

    /**
     * Current window that is shown
     */
    shared_ptr<GUIWindow> current_window;

    /**
     * Whether or not Update is called
     */
    bool game_running;

    /**
     * Whether or not the whole application should redraw
     */
    bool force_redraw;

    /**
     * If Level change has been initiated
     */
    bool change_level;

    /**
     * Whether or not the app should close
     */
    bool exit_application = true;

    /**
     * Error message to print if something goes wrong
     */
    string error_message;
public:
    /**
     * Default constructor
     */
    GameManager();

    /**
     * Starts and runs the game
     */
    void Run();

    /**
     * Tells the GameWindow to fecth entites in a given square
     * 
     * @param position Center of the square
     * @param radius Span of the square
     * 
     * @return vector of all found GameObject pointers
     */
    vector<shared_ptr<GameObject>> GetEntitiesInSquare(const IVector2& position, const int& radius);

    /**
     * Tells the GameWindow to fetch GameObject TileType pair at given position
     * 
     * @param position Position to look at
     * 
     * @return GameObject TileType pair at given location
     */
    TileGameObjectPair GetGameObjectAtPosition(const IVector2& position);

    /**
     * Tells the GameWindow to fetch all roads near given position
     * 
     * @param position Position to look from
     * 
     * @return Vector of path GameObject pointers
     */
    vector<shared_ptr<GameObject>> GetPathsNearPosition(const IVector2& position);

    /**
     * Tells the GameWindow to fetch all roads in the current map
     * 
     * @return vector of path GameObject pointers
     */
    vector<shared_ptr<GameObject>> GetAllPaths();
    
    /**
     * Tells the DefenderDefinitionHandler to fetch all DefenderTemplate instances
     * 
     * @return vector of DefenderTemplate instances
     */
    vector<DefenderTemplate> GetDefenderTemplates();

    /**
     * Tells the DefenderDefinitionHandler to fetch a random DefenderTemplate
     * 
     * @return random DefenderTemplate
     */
    DefenderTemplate GetRandomDefenderTemplate();

    /**
     * Tells the AttackerDefinitionHandler to fetch a specific AttackerTemplate
     * 
     * @param name Name of the template
     * 
     * @return AttackerTemplate
     */
    AttackerTemplate GetAttackerTemplate(const string& name);

    /**
     * Tells the AttackerDefinitionHandler to fetch names of all attacker templates
     * 
     * @return vector of strings (names)
     */
    vector<string> GetAttackerTemplateNames();

    /**
     * Tells the AttackerDefinitionHandler to fetch all attacker templates
     * 
     * @return vector of all AttackerTemplates
     */
    vector<AttackerTemplate> GetAttackerTemplates();

    /**
     * Tells the GameWindow to move an entity
     * 
     * @param position Position to move from
     * @param move_to Position to move to
     * 
     * @return whether or not the entity was moved
     */
    bool TryMoveEntity(const IVector2& position, const IVector2& move_to);

    /**
     * Tells the GameWindow to delete an object at given position
     * 
     * @param position Position to delete at
     */
    void DeleteObjectAtPosition(const IVector2& position);

    /**
     * Changes the current window to a window of given name
     * 
     * @param window_name Name of the window to switch to
     */
    void ChangeWindow(const string& window_name);

    /**
     * Tells the GameWindow to spawn a defender at given position
     * 
     * @param position Position to spawn the defender at
     * @param temp Defender to spawn
     * 
     * @return true if defender was spawned
     */
    bool TrySpawnDefender(const IVector2& position, const DefenderTemplate& temp);

    /**
     * Tells the GameWindow to spawn an attacker
     * 
     * @param temp Attacker to spawn
     * 
     * @return true if attacker was spawned
     */
    bool TrySpawnAttacker(const AttackerTemplate& temp);

    /**
     * Returns a pointer to GameStats
     * 
     * @return GameStats pointer
     */
    shared_ptr<GameStats> GetStats();

    /**
     * Returns a pointer to SaveGame
     * 
     * @return SaveGame pointer
     */
    shared_ptr<SaveGame> GetSaveGame();

    /**
     * Loads save game or creates a new one
     * 
     * @param new_game If new game should be created
     */
    void LoadGame(const bool& new_game);

    /**
     * Progresses the game to next level
     */
    void GoToNextLevel();

    /**
     * Calls Load on all loadable services
     */
    bool LoadData();

    /**
     * Tells the game to close on next cycle
     */
    void CloseApplication();

    /**
     * Loads a random map
     */
    bool LoadRandomMap();

protected: 

    /**
     * Initialized the GameManager
     */
    void Initialize();
 
    /**
     * Draws current window
     */
    void Draw();

    /**
     * Calls Update on all updatable services, only when game is not paused
     */
    void Update();

    /**
     * Disposes of all resources used
     */
    void Dispose();
};  