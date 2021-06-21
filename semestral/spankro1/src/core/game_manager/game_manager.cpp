#include "game_manager.h"

using namespace chrono;

GameManager::GameManager()
{
    error_message = "";
    game_running = false;
    force_redraw = false;
    change_level = false;
}

void GameManager::Dispose()
{
    drawer.Dispose();
    input_handler.Dispose();
    gui_windows.clear();
    loadable_objects.clear();
    updatable_services.clear();
}

void GameManager::Run()
{
    Initialize();

    auto current = high_resolution_clock::now();
    auto previous = high_resolution_clock::now();
    while(!exit_application)
    {
        int input = input_handler.HandleInput();
        if(input != -1)
            current_window->HandleInput(input, *this);
        if(exit_application)
            break;
        Draw();
        force_redraw = false;

        Update();

        current = high_resolution_clock::now();
        auto delta_time = duration_cast<milliseconds>(current - previous).count();
        if(delta_time < DELTA_TIME)
            this_thread::sleep_for(milliseconds(DELTA_TIME - delta_time));

        previous = high_resolution_clock::now();
    }
    Dispose();
    if(error_message != "")
        cout << error_message << endl;

}

shared_ptr<GameStats> GameManager::GetStats()
{
    return dynamic_pointer_cast<GameStats>(init_objects["Stats"]);
}

shared_ptr<SaveGame> GameManager::GetSaveGame()
{
    return dynamic_pointer_cast<SaveGame>(loadable_objects["Save"]);
}


vector<shared_ptr<GameObject>> GameManager::GetEntitiesInSquare(const IVector2& position, const int& radius)
{
    return dynamic_pointer_cast<GameWindow>(gui_windows["Game"])->GetEntitiesInSquare(position, radius);
}

vector<shared_ptr<GameObject>> GameManager::GetPathsNearPosition(const IVector2& position)
{
    return dynamic_pointer_cast<GameWindow>(gui_windows["Game"])->GetPathsNearPosition(position);
}

TileGameObjectPair GameManager::GetGameObjectAtPosition(const IVector2& position)
{
    return dynamic_pointer_cast<GameWindow>(gui_windows["Game"])->GetGameObjectAtPosition(position);
}

vector<shared_ptr<GameObject>> GameManager::GetAllPaths()
{
    return dynamic_pointer_cast<GameWindow>(gui_windows["Game"])->GetAllPaths();
}

bool GameManager::TrySpawnAttacker(const AttackerTemplate& temp)
{
    shared_ptr<AttackerEntity> attacker = dynamic_pointer_cast<GameWindow>(gui_windows["Game"])->TrySpawnAttacker(temp);
    if(attacker == nullptr)
        return false;
    
    shared_ptr<GameStats> stats = GetStats();
    stats->SetGold(stats->GetGold() - temp.cost);

    attacker->SetOnEndCallback([&]()
    {   
        GetStats()->DecrementLives();
    });
    attacker->SetOnDestroyCallback([&](const IVector2& position)
    {
        DeleteObjectAtPosition(position);
    });
    dynamic_pointer_cast<AttackerDefinitionHandler>(loadable_objects["AttackerTemplates"])->IncrementTemplateUse(temp.name);
    return true;
}

bool GameManager::TrySpawnDefender(const IVector2& position, const DefenderTemplate& temp)
{  
    shared_ptr<DefenderEntity> defender = dynamic_pointer_cast<GameWindow>(gui_windows["Game"])->TrySpawnDefender(position, temp);
    if(defender == nullptr)
        return false;
    
    dynamic_pointer_cast<DefenderDefinitionHandler>(loadable_objects["DefenderTemplates"])->IncrementTemplateUse(temp.name);
    return true;
}

const AttackerTemplate& GameManager::GetAttackerTemplate(const string& name)
{
    return dynamic_pointer_cast<AttackerDefinitionHandler>(loadable_objects["AttackerTemplates"])->GetTemplate(name);
}

vector<string> GameManager::GetAttackerTemplateNames()
{
    return dynamic_pointer_cast<AttackerDefinitionHandler>(loadable_objects["AttackerTemplates"])->GetTemplateNames();
}

vector<AttackerTemplate> GameManager::GetAttackerTemplates()
{
    return dynamic_pointer_cast<AttackerDefinitionHandler>(loadable_objects["AttackerTemplates"])->GetTemplates();
}

bool GameManager::TryMoveEntity(const IVector2& position, const IVector2& move_to)
{
    return dynamic_pointer_cast<GameWindow>(gui_windows["Game"])->TryMoveEntity(position, move_to);
}

void GameManager::DeleteObjectAtPosition(const IVector2& position)
{
    dynamic_pointer_cast<GameWindow>(gui_windows["Game"])->DeleteObjectAtPosition(position);
}

void GameManager::LoadGame(const bool& new_game)
{
    shared_ptr<SaveGame> save_game = GetSaveGame();
    if(new_game)
        save_game->NewGame();
    shared_ptr<LevelHandler> levels = dynamic_pointer_cast<LevelHandler>(loadable_objects["Levels"]);
    levels->GoToSpecificLevel(save_game->GetLevel());
    GetStats()->SetStats(levels->GetCurrentLevel(), *save_game);
} 

void GameManager::GoToNextLevel()
{
    shared_ptr<SaveGame> save_game = GetSaveGame();
    shared_ptr<LevelHandler> levels = dynamic_pointer_cast<LevelHandler>(loadable_objects["Levels"]);
    shared_ptr<GameStats> stats = GetStats();
    levels->GoToNextLevel();
    save_game->SetLevel(levels->GetCurrentLevelId());
    stats->SetStats(levels->GetCurrentLevel(), *save_game);
    LoadRandomMap();
    ChangeWindow("Game");
}

void GameManager::Draw()
{
    IVector2 offset(1,1);
    if(force_redraw)
        drawer.ClearAll();
    current_window->Draw(drawer, offset);
    force_redraw = false;
}

void GameManager::Update()
{
    if(game_running)
    {
        for(const auto& updatable : updatable_services)
            updatable.second->Update(*this);
    }
}

bool GameManager::LoadData()
{
    for(const auto& loadable : loadable_objects)
    {
        if(!loadable.second->Load())
        {
            error_message = loadable.second->GetError();
            exit_application = true;
            return false;
        }
    }
    return true;
}

void GameManager::Initialize()
{
    loadable_objects["DefenderTemplates"] = make_shared<DefenderDefinitionHandler>();
    loadable_objects["AttackerTemplates"] = make_shared<AttackerDefinitionHandler>();
    loadable_objects["Maps"] = make_shared<MapHandler>();
    loadable_objects["Levels"] = make_shared<LevelHandler>();
    loadable_objects["Save"] = make_shared<SaveGame>();
    loadable_objects["AIAgent"] = make_shared<AIAgent>();
    if(!LoadData())
        return;

    drawer.Initialize();
    input_handler.Initialize();

    gui_windows["MainMenu"] = make_shared<MainMenuWindow>();
    gui_windows["Game"] = make_shared<GameWindow>();
    gui_windows["LevelFinished"] = make_shared<LevelFinishedWindow>();
    for(const auto& window : gui_windows)
        window.second->Initialize();

    init_objects["Game"] = dynamic_pointer_cast<GameWindow>(gui_windows["Game"]);
    init_objects["Stats"] = make_shared<GameStats>();
    for(const auto& init : init_objects)
        init.second->Initialize(*this);

    updatable_services["Game"] = dynamic_pointer_cast<GameWindow>(gui_windows["Game"]);
    updatable_services["AIAgent"] = dynamic_pointer_cast<AIAgent>(loadable_objects["AIAgent"]);
    updatable_services["Stats"] = dynamic_pointer_cast<GameStats>(init_objects["Stats"]);

    current_window = gui_windows["MainMenu"];
    exit_application = false;
    game_running = false;
    force_redraw = false;
}

void GameManager::ChangeWindow(const string& window_name)
{
    force_redraw = true;
    current_window = gui_windows[window_name];
    shared_ptr<GameWindow> is_game_window = dynamic_pointer_cast<GameWindow>(current_window);
    if(is_game_window != nullptr)
        game_running = true;
    else
        game_running = false;
}

bool GameManager::LoadRandomMap()
{
    fstream map;
    random_device rand;
    string chosen_map = dynamic_pointer_cast<MapHandler>(loadable_objects["Maps"])->GetRandomMap();
    error_message = dynamic_pointer_cast<GameWindow>(gui_windows["Game"])->LoadMap(chosen_map);
    exit_application = error_message != "";
    return exit_application;
}

vector<DefenderTemplate> GameManager::GetDefenderTemplates()
{
    return dynamic_pointer_cast<DefenderDefinitionHandler>(loadable_objects["DefenderTemplates"])->GetTemplates();
}

const DefenderTemplate& GameManager::GetRandomDefenderTemplate()
{
    return dynamic_pointer_cast<DefenderDefinitionHandler>(loadable_objects["DefenderTemplates"])->GetRandomTemplate();
}

void GameManager::CloseApplication()
{
    exit_application = true;
}