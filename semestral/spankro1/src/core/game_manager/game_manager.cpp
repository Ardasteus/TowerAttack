#include "game_manager.h"

using namespace chrono;

GameManager::GameManager()
: game_window(GAME_WIDTH + WINDOW_BORDER , GAME_HEIGHT + WINDOW_BORDER, IVector2(0,0), COLOR_WHITE, COLOR_BLACK)
{
    error_message = "";
    game_running = false;
    force_redraw = false;
    change_level = false;
    stat_update = 0;
    ai_update = 0;
}

GameManager::~GameManager()
{
    gui_windows.clear();
    attackers.clear();
    defenders.clear();
    defenders_to_draw.clear();
    attackers_to_remove.clear();
}

void GameManager::Run()
{
    Initialize();

    auto current = high_resolution_clock::now();
    auto previous = high_resolution_clock::now();
    while(!exit_application)
    {
        int input = input_handler.HandleInput();
        current_window->HandleInput(input);
        if(exit_application)
            break;
        Draw();
        force_redraw = false;
        defenders_to_draw.clear();
        path_to_draw.clear();

        Update();
        if(change_level)
        {
            change_level = false;
            ChangeWindow("LevelFinished");
        }

        current = high_resolution_clock::now();
        auto delta_time = duration_cast<milliseconds>(current - previous).count();
        if(delta_time < DELTA_TIME)
            this_thread::sleep_for(milliseconds(DELTA_TIME - delta_time));

        previous = high_resolution_clock::now();
    }

    if(error_message != "")
        cout << error_message << endl;
}

vector<TileGameObjectPair> GameManager::GetGameObjectsInSquare(const IVector2& position, const int& radius) const
{
    vector<TileGameObjectPair> result;
    IVector2 left_corner = position - IVector2(radius, radius);
    int diameter = 2 * radius;
    for (int i = 0; i <= diameter; i++)
    {
        for (int j = 0; j <= diameter; j++)
        {
            IVector2 pos = left_corner + IVector2(i,j);
            TileGameObjectPair obj = GetGameObjectAtPosition(pos);
            if(obj.game_object != nullptr)
                result.push_back(obj);
        }
        
    }
    return result;
}

vector<TileGameObjectPair> GameManager::GetGameObjectsInCross(const IVector2& position) const
{
    vector<TileGameObjectPair> result;
    vector<IVector2> positions;
    positions.push_back(position + IVector2(0, 1));
    positions.push_back(position + IVector2(1, 0));
    positions.push_back(position - IVector2(0, 1));
    positions.push_back(position - IVector2(1, 0));
    for (auto pos : positions)
    {
        TileGameObjectPair obj = GetGameObjectAtPosition(pos);
        if(obj.game_object != nullptr)
            result.push_back(obj);
    }
    return result;
}

TileGameObjectPair GameManager::GetGameObjectAtPosition(const IVector2& position) const
{
    if(position.GetX() < 0 || position.GetX() >= GAME_WIDTH || position.GetY() < 0 || position.GetY() >= GAME_HEIGHT)
        return TileGameObjectPair(TileType::Empty, nullptr);
    return TileGameObjectPair(game_map_mask[position.GetX()][position.GetY()], game_objects[position.GetX()][position.GetY()]);
}

bool GameManager::TrySpawnAttacker(const IVector2& position, const AttackerTemplate& temp)
{
    
    TileGameObjectPair cell_pair = GetGameObjectAtPosition(position);
    AttackerEntity* test = dynamic_cast<AttackerEntity*>(cell_pair.game_object.get());
    if(cell_pair.tile_type != TileType::Spawner || test != nullptr)
        return false;


    string name = temp.name + to_string(temp.count);
    shared_ptr<AttackerEntity> attacker = make_shared<AttackerEntity>(AttackerEntity(position, name, temp));

    game_objects[position.GetX()][position.GetY()] = attacker;
    attackers.insert(attacker);
    return true;
}

bool GameManager::TrySpawnDefender(const IVector2& position, const DefenderTemplate& temp)
{  
    TileGameObjectPair cell_pair = GetGameObjectAtPosition(position);
    if(cell_pair.tile_type != TileType::Empty)
        return false;

    string name = temp.name + to_string(temp.count);
    shared_ptr<DefenderEntity> defender = make_shared<DefenderEntity>(DefenderEntity(position, name, temp));
    game_objects[position.GetX()][position.GetY()] = defender;
    game_map_mask[position.GetX()][position.GetY()] = TileType::Tower;
    defenders.insert(defender);
    defenders_to_draw.push_back(defender);
    return true;
}

void GameManager::MoveEntity(const IVector2& position, const IVector2& move_to)
{
    TileGameObjectPair to_move = GetGameObjectAtPosition(position);
    GameObject to_add = GameObject("Empty", position, ' ', COLOR_WHITE, COLOR_BLACK);
    switch (to_move.tile_type)
    {
        case TileType::Path:
            to_add = GameObject("Path", position, '.', COLOR_WHITE, COLOR_BLACK);
            path_to_draw.push_back(to_add);
            game_objects[position.GetX()][position.GetY()] = make_shared<GameObject>(to_add);
            break;
        
        case TileType::End:
            to_add = GameObject("End", position, '$', COLOR_WHITE, COLOR_BLACK);
            path_to_draw.push_back(to_add);
            game_objects[position.GetX()][position.GetY()] = make_shared<GameObject>(to_add);
            break;

        case TileType::Spawner:
            to_add = GameObject("Spawner", position, '^', COLOR_WHITE, COLOR_BLACK);
            path_to_draw.push_back(to_add);
            game_objects[position.GetX()][position.GetY()] = make_shared<GameObject>(to_add);
            break;

        default:
            game_objects[position.GetX()][position.GetY()] = make_shared<GameObject>(GameObject("Empty", position, ' ', COLOR_WHITE, COLOR_BLACK));
            break;
    }
    game_objects[move_to.GetX()][move_to.GetY()] = to_move.game_object;
}

void GameManager::Draw()
{
    IVector2 offset(1,1);
    if(force_redraw)
    {
        drawer.ClearAll();
        if(game_running)
        {
            game_window.Draw(drawer, offset);
            for (int i = 0; i < GAME_WIDTH; i++)
                for (int j = 0; j < GAME_HEIGHT; j++)
                    game_objects[i][j]->Draw(drawer, offset);
            drawer.Refresh();
            stats_window.Draw(drawer, offset);
        }
        current_window->Draw(drawer, offset);
        return;
    }
    if(game_running)
    {
        game_window.Draw(drawer, offset);
        for(auto defender : defenders_to_draw)
            defender->Draw(drawer, offset);

        for(auto path : path_to_draw)
            path.Draw(drawer, offset);

        for(auto attacker : attackers)
            attacker->Draw(drawer, offset);

        drawer.Refresh();
        stats_window.Draw(drawer, offset);
    }

    current_window->Draw(drawer, offset);
}

void GameManager::Update()
{
    if(game_running)
    {
        for(auto defender : defenders)
            defender->Update(*this);

        for(auto to_delete : attackers_to_remove)
            attackers.erase(to_delete);
            
        attackers_to_remove.clear();

        for(auto attacker : attackers)
        {
            if(change_level)
                return;

            attacker->Update(*this);
        }

        for(auto to_delete : attackers_to_remove)
            attackers.erase(to_delete);

        attackers_to_remove.clear();
    }


}

void GameManager::Initialize()
{
    loadable_objects["DefenderTemplates"] = make_shared<DefenderDefinitionHandler>();
    loadable_objects["AttackerTemplates"] = make_shared<AttackerDefinitionHandler>();
    loadable_objects["Maps"] = make_shared<MapHandler>();
    loadable_objects["Levels"] = make_shared<LevelHandler>();
    loadable_objects["Save"] = make_shared<SaveGame>();
    exit_application = false;
}

void GameManager::ChangeWindow(const string& window_name)
{
    if(window_name == "Game")
        game_running = true;
    else
        game_running = false;

    force_redraw = true;
    current_window = gui_windows[window_name];
}

bool GameManager::LoadRandomMap()
{
    fstream map;
    random_device rand;
    string chosen_map = dynamic_pointer_cast<MapHandler>(loadable_objects["Maps"])->GetRandomMap();
    bool has_spawner = false;
    bool has_end = false;
    map.open("./assets/maps/" + chosen_map, ios::in);
    if(map.is_open())
    {
        for (int j = 0; j < GAME_HEIGHT; j++)
        {
            string line;
            getline(map, line);
            if((int)line.size() != GAME_WIDTH)
            {
                map.close();
                error_message = "Map (" + chosen_map + ") failed to load: invalid size of the map. " +
                "Should be width: " + to_string(GAME_WIDTH) + " height: " + to_string(GAME_HEIGHT) + ".";
                exit_application = true;
                return false;
            }
            for (int i = 0; i < GAME_WIDTH; i++)
            {
                char current_char = line[i];
                switch (current_char)
                {
                    case '.':
                        game_objects[i][j] = make_shared<GameObject>(GameObject("Path", IVector2(i,j), '.', COLOR_WHITE, COLOR_BLACK));
                        game_map_mask[i][j] = TileType::Path;
                        break;

                    case '^':
                        if(has_spawner)
                        {
                            map.close();
                            error_message = "Map (" + chosen_map + ") failed to load: Multiple spawners (^) are not allowed.";
                            exit_application = true;
                            return false;
                        }
                        game_objects[i][j] = make_shared<GameObject>(GameObject("Spawner", IVector2(i,j), '^', COLOR_WHITE, COLOR_BLACK));
                        game_map_mask[i][j] = TileType::Spawner;
                        SpawnLocation = IVector2(i, j);
                        has_spawner = true;
                        break;

                    case '$':
                        if(has_end)
                        {
                            map.close();
                            error_message = "Map (" + chosen_map + ") failed to load: Multiple ends ($) are not allowed.";
                            exit_application = true;
                            return false;
                        }
                        game_objects[i][j] = make_shared<GameObject>(GameObject("End", IVector2(i,j), '$', COLOR_WHITE, COLOR_BLACK));
                        game_map_mask[i][j] = TileType::End;
                        has_end = true;
                        break;

                    case 'x':
                        game_objects[i][j] = make_shared<GameObject>(GameObject("Unavailable", IVector2(i,j), 'x', COLOR_RED, COLOR_BLACK));
                        game_map_mask[i][j] = TileType::Unavailable;
                        break;
                    
                    default:
                        game_objects[i][j] = make_shared<GameObject>(GameObject("Empty", IVector2(i,j), ' ', COLOR_WHITE, COLOR_BLACK));
                        game_map_mask[i][j] = TileType::Empty;
                        break;
                }
            }
        }
        map.close();
        if(!has_end)
        {
            error_message = "Map (" + chosen_map + ") failed to load: Map has to have atleast one end ($).";
            exit_application = true;
            return false;
        }
        if(!has_spawner)
        {
            error_message = "Map (" + chosen_map + ") failed to load: Map has to have atleast one spawner (^).";
            exit_application = true;
            return false;
        }
        return true;
    }
    else
    {
        error_message = "Map (" + chosen_map + ") failed to load: File (./assets/maps/" + chosen_map + ") could not be opened.";
        exit_application = true;
        return false;
    }
}

DefenderTemplate GameManager::GetRandomDefenderTemplate()
{
    return dynamic_pointer_cast<DefenderDefinitionHandler>(loadable_objects["DefenderTemplates"])->GetRandomTemplate();
}