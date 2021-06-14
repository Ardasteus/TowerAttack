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

const int TOTAL_WIDTH = 100;
const int TOTAL_HEIGHT = 23;
const int GAME_WIDTH = 60;
const int GAME_HEIGHT = 20;
const int WINDOW_BORDER = 2;
const int ATTACKER_UPDATE_TIME = 3;
const int DEFENDER_UPDATE_TIME = 5;
const int AI_UPDATE_TIME = 150;
const int STAT_UPDATE_TIME = 200;
const int DELTA_TIME = 33;

/**
 * Mega class that handles all communication between game logic and UI, loading data, etc.
 */
class GameManager
{
protected:
    /**
     * Game window in which all GameObject instances are drawn
     */
    BaseWindow game_window;

    /**
     * Stats window, shows relevant GameStats properties
     */
    GameStatsWindowHandler stats_window;

    /**
     * 2D array of GameObject instances, acts as a map.
     */
    shared_ptr<GameObject> game_objects[GAME_WIDTH][GAME_HEIGHT];

    /**
     * Number of empty spots on the map
     */
    int total_empty = 0;

    /**
     * 2D array of TileType instances, acts as a mask as to where for example the paths are.
     */
    TileType game_map_mask[GAME_WIDTH][GAME_HEIGHT];

    /**
     * Vector of avilable map file names
     */
    vector<string> map_files;

    /**
     * Set of AttackerEntity instances, stores as GameObject
     */
    set<shared_ptr<GameObject>, GameObjectComparator> attackers;

    /**
     * Set of DefenderEntity instances, stores as GameObject
     */
    set<shared_ptr<GameObject>, GameObjectComparator> defenders;

    /**
     * Vector of paths that need drawing
     */
    vector<GameObject> path_to_draw;

    /**
     * Vector of entites that need to be drawn, used exclusively for defenders as attackers always draw.
     */
    vector<shared_ptr<GameObject>> defenders_to_draw;

    /**
     * Map storing available AttackerTemplate objects
     */
    map<string, AttackerTemplate> attacker_templates;

    /**
     * Map storing available DefenderTemplate objects
     */
    map<string, DefenderTemplate> defender_templates;

    /**
     * Location of the spawner
     */
    IVector2 SpawnLocation;

    /**
     * GameStats instance
     */
    GameStats stats;

    /**
     * SaveGame instance
     */
    SaveGame save_game;

    /**
     * Drawer instance
     */
    Drawer drawer;

    /**
     * InputHandler window
     */
    InputHandler input_handler;

    /**
     * Map of all GUIWindow instances used in the game
     */
    map<string, shared_ptr<GUIWindow>> gui_windows;

    /**
     * Current GUIWindow that recieves input and draws
     */
    shared_ptr<GUIWindow> current_window;

    /**
     * Whether or not the game is running/paused
     */
    bool game_running;

    /**
     * Whether or not should the whole screen be redrawn
     */
    bool force_redraw;

    /**
     * Whether or not a level should be changed
     */
    bool change_level;

    /**
     * AI update timer
     */
    int ai_update;

    /**
     * Stat update timer
     */
    int stat_update;

    /**
     * Whether or not the application should exit
     */
    bool exit_application = false;

    /**
     * Error message to be displayed to stdout when app closes.
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
     * Returns a vector of TileGameObjectPair objects in square of given radius
     * 
     * @param position Center of the lookup square
     * @param radius Span of the square
     */
    vector<TileGameObjectPair> GetGameObjectsInSquare(IVector2 position, int radius) const;

    /**
     * Returns a TileGameObjectPair object with values from given position
     * 
     * @param position Position to look at
     */
    TileGameObjectPair GetGameObjectAtPosition(IVector2 position) const;

    /**
     * Returns a vector of TileGameObjectPair objects neighboring the position, excluding diagonal neighbors
     * 
     * @param position Center of cross
     */
    vector<TileGameObjectPair> GetGameObjectsInCross(IVector2 position) const;
    
    /**
     * Moves an entity on the 2D grid
     * 
     * @param position Position of entity to move
     * @param move_to Where to move the entity
     */
    void MoveEntity(IVector2 position, IVector2 move_to);

    /**
     * Changes the current active GUIWindow
     * 
     * @param window_name Name of the window to swap to. Key in gui_windows
     */
    void ChangeWindow(string window_name);

protected: 

    /**
     * Creates and adds new GUIWindow to gui_windows
     * 
     * @param name Name of the window
     * @param width Width of the window
     * @param height Height of the window
     * @param position Position of the window
     */
    shared_ptr<GUIWindow> AddGUIWindow(string name, int width, int height, IVector2 position);

    /**
     * Initializes the game, loads all resources, creates all windows.
     */
    void Initialize();

    /**
     * Draws current GUIWindow and the game if game is not paused
     */
    void Draw() const;

    /**
     * Runs update on all entites, defenders first, attackers second. Also runs Stat and AI updates.
     */
    void Update();

    /**
     * Disposes of all resources used by the game
     */
    void Dispose();

    /**
     * Loads all available AttackerTemplate objects from a file
     */
    void LoadAttackerDefinitions();

    /**
     * Loads all available DefenderTemplate objects from a file
     */
    void LoadDefenderDefinitions();

    /**
     * Loads all available maps from a file
     */
    void LoadMaps();

    /**
     * Picks a random map from available maps and loads it
     */
    void LoadRandomMap();

    /**
     * Tries to spawn an AttackerEntity at given position using given template
     * 
     * @param position Where to spawn the entity
     * @param template_name Template to use
     * @return Whether or not the entity was spawned
     */
    bool TrySpawnAttacker(IVector2 position, string template_name);

    /**
     * Tries to spawn an DefenderEntity at given position using given template
     * 
     * @param position Where to spawn the entity
     * @param template_name Template to use
     * @return Whether or not the entity was spawned
     */
    bool TrySpawnDefender(IVector2 position, string template_name);

    /**
     * AI update, tries to spawn a random DefenderEntity at a random position, 5 times.
     */
    void DefenderAIUpdate();

    /**
     * Updates the stats of the game, giving the player gold based on income.
     */
    void StatUpdate();

    /**
     * Switches the game to specific level and notifies if this is a new game or not. If it is a new game, overwrites the old one.
     * 
     * @param level Level to go to
     * @param new_game If true overwrites the current save game
     */
    void GoToLevel(int level, bool new_game);
};  