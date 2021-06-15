#include "game_manager.h"

using namespace chrono;

GameManager::GameManager()
: game_window(GAME_WIDTH + WINDOW_BORDER , GAME_HEIGHT + WINDOW_BORDER, IVector2(0,0), COLOR_WHITE, COLOR_BLACK)
, stats_window(GAME_WIDTH + WINDOW_BORDER, TOTAL_HEIGHT - GAME_HEIGHT, IVector2(0, GAME_HEIGHT + WINDOW_BORDER))
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
    attacker_templates.clear();
    defender_templates.clear();
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

bool GameManager::TrySpawnAttacker(const IVector2& position, const string& template_name)
{
    auto found = attacker_templates.find(template_name);
    if(found == attacker_templates.end())
        return false;
    
    TileGameObjectPair cell_pair = GetGameObjectAtPosition(position);
    AttackerEntity* test = dynamic_cast<AttackerEntity*>(cell_pair.game_object.get());
    if(cell_pair.tile_type != TileType::Spawner || test != nullptr)
        return false;
    AttackerTemplate temp_template = found->second;

    if(stats.player_gold - temp_template.cost < 0)
        return false;

    string name = temp_template.name + to_string(temp_template.count);
    temp_template.health += save_game.bonus_hp;
    shared_ptr<AttackerEntity> attacker = make_shared<AttackerEntity>(AttackerEntity(position, name, temp_template));
    attacker->SetOnEndCallback([&]()
    {
        stats.lives--;
        if(stats.lives == 0)
            change_level = true;

        stats.InvokeUpdate();
    });
    attacker->SetOnDestroyCallback([&](IVector2 position)
    {
        TileGameObjectPair to_delete = GetGameObjectAtPosition(position);
        GameObject to_add = GameObject("Dummy", position, ' ', COLOR_WHITE, COLOR_BLACK);
        stats.ai_gold += stats.ai_income;
        switch (to_delete.tile_type)
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
        attackers_to_remove.push_back(to_delete.game_object);
    });
    game_objects[position.GetX()][position.GetY()] = attacker;
    attacker_templates[template_name].count++;
    attackers.insert(attacker);
    stats.player_gold -= temp_template.cost;
    stats.InvokeUpdate();
    return true;
}

bool GameManager::TrySpawnDefender(const IVector2& position, const string& template_name)
{
    auto found = defender_templates.find(template_name);
    if(found == defender_templates.end())
        return false;
    
    TileGameObjectPair cell_pair = GetGameObjectAtPosition(position);
    if(cell_pair.tile_type != TileType::Empty)
        return false;

    DefenderTemplate temp_template = found->second;
    string name = temp_template.name + to_string(temp_template.count);
    shared_ptr<DefenderEntity> defender = make_shared<DefenderEntity>(DefenderEntity(position, name, temp_template));
    game_objects[position.GetX()][position.GetY()] = defender;
    game_map_mask[position.GetX()][position.GetY()] = TileType::Tower;
    defender_templates[template_name].count++;
    defenders.insert(defender);
    defenders_to_draw.push_back(defender);
    total_empty--;
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
        DefenderAIUpdate();
        StatUpdate();
    }


}

void GameManager::Initialize()
{
    //Loading Phase
    if(!LoadMaps())
        return;
    if(!stats.LoadLevels(error_message))
        return;
    if(!LoadAttackerDefinitions())
        return;
    if(!LoadDefenderDefinitions())
        return;

    //Initialization Phase
    drawer.Initialize();
    input_handler.Initialize();
    game_window.Initialize();
    stats_window.Initialize();
    stats.SetUpdateFunction([&]()
    {
        stats_window.UpdateWindow(stats);
    });
    ControlCreator creator;

    //Main menu Initialization
    shared_ptr<GUIWindow> main_menu = AddGUIWindow("MainMenu", TOTAL_WIDTH + WINDOW_BORDER, TOTAL_HEIGHT + WINDOW_BORDER, IVector2(0,0));
    shared_ptr<Button> continue_game_btn = creator.CreateButton("Continue Game", IVector2(0,0), 10);
    continue_game_btn->AddOnClickEvent([&]() -> void
    {
        save_game.Load();
        GoToLevel(save_game.current_level, false);
        ChangeWindow("Game");
    });
    shared_ptr<Button> start_game_btn = creator.CreateButton("Start Game", IVector2(0,1), 10);
    start_game_btn->AddOnClickEvent([&]() -> void
    {
        GoToLevel(0, true);
        ChangeWindow("Game");
    });
    shared_ptr<Button> close_btn = creator.CreateButton("Close", IVector2(0,2), 10);
    close_btn->AddOnClickEvent([&]() -> void
    {
        exit_application = true;
    });
    main_menu->AddElement(continue_game_btn);
    main_menu->AddElement(start_game_btn);
    main_menu->AddElement(close_btn);

    //Game Menu Init (the picking of attackers)
    shared_ptr<GUIWindow> game_menu = AddGUIWindow("Game", TOTAL_WIDTH - GAME_WIDTH, TOTAL_HEIGHT + WINDOW_BORDER, IVector2(GAME_WIDTH + WINDOW_BORDER,0));
    IVector2 button_offset = IVector2(0,0);
    for(auto pairs : attacker_templates)
    {
        string attacker_name = pairs.first;
        AttackerTemplate attacker_template = pairs.second;
        shared_ptr<Button> new_btn = creator.CreateButton("Spawn " + attacker_name + " (" + to_string(attacker_template.cost) +")", button_offset, 
        TOTAL_WIDTH - GAME_WIDTH - WINDOW_BORDER);
        new_btn->AddOnClickEvent([attacker_name,this]() -> void
        {
            TrySpawnAttacker(SpawnLocation, attacker_name);
        });
        game_menu->AddElement(new_btn);
        button_offset.SetY(button_offset.GetY() + 1);
    }
    shared_ptr<Button> back_btn = creator.CreateButton("Back", button_offset, TOTAL_WIDTH - GAME_WIDTH - WINDOW_BORDER);
    back_btn->AddOnClickEvent([&]() -> void
    {
        save_game.Save();
        ChangeWindow("MainMenu");
    });
    game_menu->AddElement(back_btn);

    shared_ptr<GUIWindow> level_finished_menu = AddGUIWindow("LevelFinished", TOTAL_WIDTH - GAME_WIDTH, TOTAL_HEIGHT + WINDOW_BORDER, IVector2(0,0));
    shared_ptr<Label> upgrade_info = creator.CreateLabel("Good Job! Choose an Upgrade", IVector2(0,0));
    shared_ptr<Button> improve_gold = creator.CreateButton("Upgrade Starting Gold (100)", IVector2(0,1), TOTAL_WIDTH - GAME_WIDTH - WINDOW_BORDER);
    improve_gold->AddOnClickEvent([&]() -> void
    {
        save_game.bonus_gold += 100;
        save_game.Save();
        GoToLevel(stats.current_level + 1, false);
        ChangeWindow("Game");
    });
    shared_ptr<Button> improve_income = creator.CreateButton("Upgrade Income (20)", IVector2(0,2), TOTAL_WIDTH - GAME_WIDTH - WINDOW_BORDER);
    improve_income->AddOnClickEvent([&]() -> void
    {
        save_game.bonus_income += 20;
        save_game.Save();
        GoToLevel(stats.current_level + 1, false);
        ChangeWindow("Game");
    });
    shared_ptr<Button> improve_hp = creator.CreateButton("Upgrade HP (100)", IVector2(0,3), TOTAL_WIDTH - GAME_WIDTH - WINDOW_BORDER);
    improve_hp->AddOnClickEvent([&]() -> void
    {
        save_game.bonus_hp += 100;
        save_game.Save();
        GoToLevel(stats.current_level + 1, false);
        ChangeWindow("Game");
    });
    level_finished_menu->AddElement(upgrade_info);
    level_finished_menu->AddElement(improve_gold);
    level_finished_menu->AddElement(improve_income);
    level_finished_menu->AddElement(improve_hp);
    
    current_window = gui_windows["MainMenu"];
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

shared_ptr<GUIWindow> GameManager::AddGUIWindow(const string& name, const int& width, const int& height, const IVector2& position)
{
    auto found = gui_windows.find(name);
    if(found != gui_windows.end())
        return nullptr;

    shared_ptr<GUIWindow> window = make_shared<GUIWindow>(GUIWindow(name, width, height, position));
    window->Initialize();
    gui_windows[name] = window;
    return window;
}

void GameManager::DefenderAIUpdate()
{
    if(total_empty == 0)
        return;
    ai_update++;
    if(ai_update == AI_UPDATE_TIME)
    {
        ai_update = 0;
        int tries = 5;
        bool spawned = false;
        random_device rand;
        mt19937 rng(rand());
        uniform_int_distribution<int> rand_dist(0, defender_templates.size() - 1);
        uniform_int_distribution<int> rand_x(0, GAME_WIDTH - 1);
        uniform_int_distribution<int> rand_y(0, GAME_HEIGHT - 1);
        while(!spawned && tries > 0)
        {
            auto index = defender_templates.begin();
            advance(index, rand_dist(rng));
            DefenderTemplate def_template = index->second;
            if(stats.ai_gold - def_template.cost < 0)
            {
                tries--;
                continue;
            }
            string def_template_name = index->first;
            IVector2 rand_position(rand_x(rng), rand_y(rng));
            spawned = TrySpawnDefender(rand_position, def_template_name);
            if(spawned)
            {
                stats.ai_gold -= def_template.cost;
                break;
            }
            tries--;
        }
    }
}

void GameManager::StatUpdate()
{
    stat_update++;
    if(stat_update == STAT_UPDATE_TIME)
    {
        //stats.ai_gold += stats.ai_income;
        if(stats.player_gold + stats.player_income > 999)
            stats.player_gold = 999;
        else    
            stats.player_gold += stats.player_income;

        stat_update = 0;
        stats.InvokeUpdate();
    }
}

bool GameManager::LoadAttackerDefinitions()
{
    fstream attacker_definitions;
    attacker_definitions.open("./assets/attacker_definitions", ios::in);
    if(attacker_definitions.is_open())
    {
        string line;
        getline(attacker_definitions, line);
        while(getline(attacker_definitions, line))
        {
            vector<string> values = StringUtils::SplitStringByDelimiter(line, ";");
            if(values.size() != 6)
            {
                attacker_definitions.close();
                error_message = "Attacker definitions failed to load: Invalid number of arguments, should be 6.";
                return false;
            }
            AttackerTemplate new_template = AttackerTemplate(values[0], stoi(values[1]), stoi(values[2]), COLOR_CYAN, COLOR_BLACK, 
            values[3][0], values[4], values[5]);
            attacker_templates[new_template.name] = new_template;
        }
        attacker_definitions.close();
        return true;
    }
    else
    {
        error_message = "Attacker definitions failed to load: File (./assets/attacker_definitions) could not be opened.";
        return false;
    }
}

bool GameManager::LoadDefenderDefinitions()
{
    fstream defender_definitions;
    defender_definitions.open("./assets/defender_definitions", ios::in);
    if(defender_definitions.is_open())
    {
        string line;
        getline(defender_definitions, line);
        while(getline(defender_definitions, line))
        {
            vector<string> values = StringUtils::SplitStringByDelimiter(line, ";");
            if(values.size() != 7)
            {
                defender_definitions.close();
                error_message = "Defender definitions failed to load: Invalid number of arguments, should be 7.";
                return false;
            }
            shared_ptr<AttackMode> mode = make_shared<ClosestAttackMode>();
            DefenderTemplate new_template = DefenderTemplate(values[0], COLOR_YELLOW, COLOR_BLACK, 
            values[4][0], stoi(values[2]), stoi(values[1]), stoi(values[3]),
            mode, values[6]);
            defender_templates[new_template.name] = new_template;
        }
        defender_definitions.close();
        return true;
    }
    else
    {
        error_message = "Defender definitions failed to load: File (./assets/defender_definitions) could not be opened.";
        return false;
    }
}

bool GameManager::LoadRandomMap()
{
    total_empty = 0;
    fstream map;
    random_device rand;
    mt19937 rng(rand());
    uniform_int_distribution<int> rand_dist(0, map_files.size() - 1);
    auto index = map_files.begin();
    bool has_spawner = false;
    bool has_end = false;
    advance(index, rand_dist(rng));
    string chosen_map = *index;
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
                        total_empty++;
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

bool GameManager::LoadMaps()
{
    fstream map_list;
    map_list.open("./assets/maps/map_list", ios::in);
    if(map_list.is_open())
    {
        string line;
        getline(map_list, line);
        while(getline(map_list, line))
            map_files.push_back(line);

        map_list.close();

        if(map_files.size() == 0)
        {
            error_message = "Maps could not be loaded: No maps found.";
            return false;
        }

        return true;
    }
    else
    {
        error_message = "Maps could not be loaded: File (./assets/maps/map_list) could not be opened.";
        return false;
    }
}

void GameManager::GoToLevel(const int& level, const bool& new_game)
{
    attackers.clear();
    defenders.clear();
    defenders_to_draw.clear();
    change_level = false;
    ai_update = 0;
    stat_update = 0;
    if(!new_game)
        save_game.Load();
    else
        save_game = SaveGame();
    stats.SetSpecificLevel(level, save_game);
    save_game.Save();
    LoadRandomMap();
    force_redraw = true;
}