#include "game_manager.h"

using namespace chrono;

GameManager::GameManager()
: game_window(GAME_WIDTH + 2 , GAME_HEIGHT + 2, IVector2(0,0), COLOR_WHITE, COLOR_BLACK)
{

}

void GameManager::Run()
{
    Initialize();

    auto current = high_resolution_clock::now();
    auto previous = high_resolution_clock::now();
    int delta_limit = 100;
    while(!exit_application)
    {
        int input = input_handler.HandleInput();
        current_window->HandleInput(input);
        Draw();
        Update();
        force_redraw = false;
        current = high_resolution_clock::now();
        auto delta_time = duration_cast<milliseconds>(current - previous).count();
        if(delta_time < delta_limit)
            this_thread::sleep_for(milliseconds(delta_limit - delta_time));

        previous = high_resolution_clock::now();
    }
    Dispose();
}

vector<TileGameObjectPair> GameManager::GetGameObjectsInSquare(IVector2 position, int radius) const
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

TileGameObjectPair GameManager::GetGameObjectAtPosition(IVector2 position) const
{
    if(position.GetX() < 0 || position.GetX() >= GAME_WIDTH || position.GetY() < 0 || position.GetY() >= GAME_HEIGHT)
        return TileGameObjectPair(TileType::Empty, nullptr);
    return TileGameObjectPair(game_map_mask[position.GetX()][position.GetY()], game_objects[position.GetX()][position.GetY()]);
}

void GameManager::TrySpawnAttacker(IVector2 position, string template_name)
{
    auto found = attacker_templates.find(template_name);
    if(found == attacker_templates.end())
        return;
    
    TileGameObjectPair cell_pair = GetGameObjectAtPosition(position);
    AttackerEntity* test = dynamic_cast<AttackerEntity*>(cell_pair.game_object.get());
    if(cell_pair.tile_type != TileType::Spawner || test != nullptr)
        return;
    AttackerTemplate temp_template = found->second;
    string name = temp_template.name + to_string(temp_template.count);
    shared_ptr<AttackerEntity> attacker = make_shared<AttackerEntity>(AttackerEntity(position, name, temp_template));
    attacker->SetOnDestroyCallback([&](IVector2 position)
    {
        shared_ptr<GameObject> to_delete = GetGameObjectAtPosition(position).game_object;
        game_objects[position.GetX()][position.GetY()] = make_shared<GameObject>(GameObject("Empty", position, ' ', COLOR_WHITE, COLOR_BLACK));
        entities.erase(to_delete);
    });
    game_objects[position.GetX()][position.GetY()] = attacker;
    attacker_templates[template_name].count++;
    entities.insert(attacker);
}

void GameManager::TrySpawnDefender(IVector2 position, string template_name)
{
    auto found = defender_templates.find(template_name);
    if(found == defender_templates.end())
        return;
    
    TileGameObjectPair cell_pair = GetGameObjectAtPosition(position);
    if(cell_pair.tile_type != TileType::Empty)
        return;

    DefenderTemplate temp_template = found->second;
    string name = temp_template.name + to_string(temp_template.count);
    shared_ptr<DefenderEntity> defender = make_shared<DefenderEntity>(DefenderEntity(position, name, temp_template));
    defender->SetOnDestroyCallback([&](IVector2 position)
    {
        shared_ptr<GameObject> to_delete = GetGameObjectAtPosition(position).game_object;
        game_objects[position.GetX()][position.GetY()] = make_shared<GameObject>(GameObject("Empty", position, ' ', COLOR_WHITE, COLOR_BLACK));
        entities.erase(to_delete);
    });
    game_objects[position.GetX()][position.GetY()] = defender;
    game_map_mask[position.GetX()][position.GetY()] = TileType::Tower;
    defender_templates[template_name].count++;
    entities.insert(defender);
}

void GameManager::MoveEntity(IVector2 position, IVector2 move_to)
{
    shared_ptr<GameObject> to_move = GetGameObjectAtPosition(position).game_object;
    game_objects[position.GetX()][position.GetY()] = make_shared<GameObject>(GameObject("Empty", position, ' ', COLOR_WHITE, COLOR_BLACK));
    game_objects[move_to.GetX()][move_to.GetY()] = to_move;
}

void GameManager::Draw() const
{
    IVector2 offset(1,1);
    if(force_redraw)
    {
        drawer.ClearAll();
        if(game_running)
        {
            game_window.Draw(drawer);
            for (int i = 0; i < GAME_WIDTH; i++)
                for (int j = 0; j < GAME_HEIGHT; j++)
                    game_objects[i][j]->Draw(drawer, offset);
            drawer.Refresh();
        }
        current_window->Draw(drawer);
        return;
    }
    if(game_running)
    {
        game_window.Draw(drawer);
        for (int i = 0; i < GAME_WIDTH; i++)
            for (int j = 0; j < GAME_HEIGHT; j++)
                game_objects[i][j]->Draw(drawer, offset);
        drawer.Refresh();
    }

    current_window->Draw(drawer);
}

void GameManager::Update()
{
    if(game_running)
    {
        for(auto entity : entities)
            entity->Update(*this);
    }
}

void GameManager::Initialize()
{
    drawer.Initialize();
    input_handler.Initialize();
    game_window.Initialize();

    for (int i = 0; i < GAME_WIDTH; i++)
    for (int j = 0; j < GAME_HEIGHT; j++)
    {
        game_objects[i][j] = make_shared<GameObject>(GameObject("Empty", IVector2(i,j), ' ', COLOR_WHITE, COLOR_BLACK));
        game_map_mask[i][j] = TileType::Empty;
    }

    for (int i = 0; i < GAME_HEIGHT; i++)
        game_map_mask[GAME_WIDTH / 2][i] = TileType::Path;

    game_map_mask[GAME_WIDTH / 2][0] = TileType::Spawner;
    game_map_mask[GAME_WIDTH / 2][GAME_HEIGHT - 1] = TileType::End;
    SpawnLocation = IVector2(GAME_WIDTH / 2, 0);

    AttackerTemplate test_attacker_template = AttackerTemplate("Attacker", 50, COLOR_BLUE, COLOR_BLACK, 'A');
    AttackerTemplate test_attacker_template2 = AttackerTemplate("Weakling", 10, COLOR_BLUE, COLOR_BLACK, 'W');
    DefenderTemplate test_defender_template = DefenderTemplate("Defender", COLOR_RED, COLOR_BLACK, 'D', 2, 5);
    defender_templates[test_defender_template.name] = test_defender_template;
    attacker_templates[test_attacker_template.name] = test_attacker_template;
    attacker_templates[test_attacker_template2.name] = test_attacker_template2;
    TrySpawnDefender(IVector2(GAME_WIDTH / 2 + 1, GAME_HEIGHT / 2), "Defender");

    //Main menu Initialization
    shared_ptr<GUIWindow> main_menu = AddGUIWindow("MainMenu", GAME_WIDTH + 2, GAME_HEIGHT + 2, IVector2(0,0));
    Button* start_game_btn = new Button("StartBtn", "Start Game", IVector2(0,0), 10, COLOR_BLUE, COLOR_BLACK, COLOR_BLACK, COLOR_BLUE);
    start_game_btn->AddOnClickEvent([&]() -> void
    {
        ChangeWindow("Game");
    });
    Button* close_btn = new Button("CloseBtn", "Close", IVector2(0,1), 10, COLOR_BLUE, COLOR_BLACK, COLOR_BLACK, COLOR_BLUE);
    close_btn->AddOnClickEvent([&]() -> void
    {
        exit_application = true;
    });
    main_menu->AddElement(start_game_btn);
    main_menu->AddElement(close_btn);

    //Game Menu Init (the picking of attackers)
    shared_ptr<GUIWindow> game_menu = AddGUIWindow("Game", GAME_WIDTH + 2, GAME_HEIGHT + 2, IVector2(GAME_WIDTH + 3,0));
    IVector2 button_offset = IVector2(0,0);
    for(auto pairs : attacker_templates)
    {
        string attacker_name = pairs.first;
        Button* new_btn = new Button("Spawn" + attacker_name, attacker_name, button_offset, GAME_WIDTH, COLOR_BLUE, COLOR_BLACK, COLOR_BLACK, COLOR_BLUE);
        new_btn->AddOnClickEvent([attacker_name,this]() -> void
        {
            TrySpawnAttacker(SpawnLocation, attacker_name);
        });
        game_menu->AddElement(new_btn);
        button_offset.SetY(button_offset.GetY() + 1);
    }

    Button* back_btn = new Button("Back", "Back", button_offset, 10, COLOR_BLUE, COLOR_BLACK, COLOR_BLACK, COLOR_BLUE);
    back_btn->AddOnClickEvent([&]() -> void
    {
        ChangeWindow("MainMenu");
    });
    game_menu->AddElement(back_btn);
    current_window = gui_windows["MainMenu"];
    game_running = false;
}

void GameManager::Dispose()
{
    attacker_templates.clear();
    defender_templates.clear();
    gui_windows.clear();
    entities.clear();

    input_handler.Dispose();
    drawer.Dispose();
}

void GameManager::ChangeWindow(string window_type)
{
    to_draw.clear();
    if(window_type == "Game")
        game_running = true;
    else
        game_running = false;

    force_redraw = true;
    current_window = gui_windows[window_type];
}

shared_ptr<GUIWindow> GameManager::AddGUIWindow(string name, int width, int height, IVector2 position)
{
    auto found = gui_windows.find(name);
    if(found != gui_windows.end())
        return nullptr;

    shared_ptr<GUIWindow> window = make_shared<GUIWindow>(GUIWindow(name, width, height, position));
    window->Initialize();
    gui_windows[name] = window;
    return window;
}