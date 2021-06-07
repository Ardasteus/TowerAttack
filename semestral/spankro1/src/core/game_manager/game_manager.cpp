#include "game_manager.h"

GameManager::GameManager()
{
    game_window = nullptr;
    game_width = 0;
    game_height = 0;
}

void GameManager::Run()
{
    bool keep_playing = true;
    while(keep_playing)
    {
        int input = input_handler.HandleInput();
        if(input == KEY_END)
            keep_playing = false;
        char key_char = (char)input;
        current_window->HandleInput(input);
        Update();
        Draw();
    }
    Dispose();
}

vector<shared_ptr<GameObject>> GameManager::GetGameObjectsInSquare(IVector2 position, int radius) const
{
    vector<shared_ptr<GameObject>> result;
    IVector2 left_corner = position - IVector2(radius, radius);
    int diameter = 2 * radius;
    for (int i = 0; i < diameter; i++)
    {
        for (int j = 0; j < diameter; j++)
        {
            IVector2 pos = position + IVector2(i,j);
            shared_ptr<GameObject> obj = GetGameObjectAtPosition(pos);
            if(obj != nullptr)
                result.push_back(obj);
        }
        
    }
    return result;
}

shared_ptr<GameObject> GameManager::GetGameObjectAtPosition(IVector2 position) const
{
    if(position.GetX() < 0 || position.GetX() >= game_width || position.GetY() < 0 || position.GetY() >= game_height)
        return nullptr;

    return game_objects[position.GetX()][position.GetY()];
}

void GameManager::Draw() const
{
    game_window->Draw(game_width, game_width, game_objects, drawer);
    current_window->Draw(drawer);
}

void GameManager::Update()
{
    return;
    for (int i = 0; i < game_width; i++)
        for (int j = 0; j < game_height; j++)
            game_objects[i][j]->Update(*this);
}

void GameManager::Initialize()
{
    drawer.Initialize();
    input_handler.Initialize();

    game_width = 20;
    game_height = 10;
    game_window = make_shared<GameWindow>(GameWindow("Game", game_width, game_height, IVector2(0,0)));
    game_window->Initialize();
    GUIWindow attacker_selector = GUIWindow("Selector", game_width, game_height, IVector2(21,0));
    attacker_selector.Initialize();
    gui_windows["Selector"] = make_shared<GUIWindow>(attacker_selector);
    current_window = gui_windows["Selector"];
}

void GameManager::Dispose()
{
    input_handler.Dispose();
    drawer.Dispose();
    for(auto vector : game_objects)
        vector.clear();

    attacker_templates.clear();
    defender_templates.clear();
    game_objects.clear();
    gui_windows.clear();
}