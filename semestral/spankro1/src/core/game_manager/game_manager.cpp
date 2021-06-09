#include "game_manager.h"

using namespace chrono;

GameManager::GameManager()
: game_window(game_width + 2 , game_height + 2, IVector2(0,0), COLOR_WHITE, COLOR_BLACK)
{

}

void GameManager::Run()
{
    auto current = high_resolution_clock::now();
    auto previous = high_resolution_clock::now();
    int delta_limit = 33;
    while(true)
    {
        int input = input_handler.HandleInput();
        if(input == KEY_END)
            break;
        char key_char = (char)input;
        current_window->HandleInput(input);
        Update();
        Draw();
        current = high_resolution_clock::now();
        auto delta_time = duration_cast<milliseconds>(current - previous).count();
        if(delta_time < delta_limit)
            this_thread::sleep_for(milliseconds(delta_limit - delta_time));

        previous = high_resolution_clock::now();
    }
    Dispose();
}

vector<shared_ptr<GameObject>> GameManager::GetGameObjectsInSquare(IVector2 position, int radius) const
{
    vector<shared_ptr<GameObject>> result;
    IVector2 left_corner = position - IVector2(radius, radius);
    int diameter = 2 * radius;
    for (int i = 0; i <= diameter; i++)
    {
        for (int j = 0; j <= diameter; j++)
        {
            IVector2 pos = left_corner + IVector2(i,j);
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
    game_window.Draw(drawer);
    IVector2 offset(1,1);
    for (int i = 0; i < game_width; i++)
        for (int j = 0; j < game_height; j++)
            game_objects[i][j]->Draw(drawer, offset);
    drawer.Refresh();

    current_window->Draw(drawer);
}

void GameManager::Update()
{
    for (int i = 0; i < game_width; i++)
        for (int j = 0; j < game_height; j++)
            game_objects[i][j]->Update(*this);
}

void GameManager::Initialize()
{
    drawer.Initialize();
    input_handler.Initialize();

    for (int i = 0; i < game_width; i++)
        for (int j = 0; j < game_height; j++)
        {
            game_objects[i][j] = make_shared<GameObject>(GameObject("Empty", IVector2(i,j), ' ', COLOR_WHITE, COLOR_BLACK));
        }

    AttackerTemplate test_attacker = AttackerTemplate("Attacker", 120, COLOR_BLUE, COLOR_BLACK, 'A');
    DefenderTemplate test_defender = DefenderTemplate("Defender", COLOR_RED, COLOR_BLACK, 'D', 2, 1);
    game_objects[0][0] = make_shared<AttackerEntity>(AttackerEntity(IVector2(0,0), test_attacker));
    game_objects[3][2] = make_shared<AttackerEntity>(AttackerEntity(IVector2(3,2), test_attacker));
    game_objects[0][2] = make_shared<DefenderEntity>(DefenderEntity(IVector2(0,2), test_defender));
    game_objects[0][0]->SetOnDestroyCallback([&](IVector2 pos) -> void
    {
        game_objects[pos.GetX()][pos.GetY()] = make_shared<GameObject>(GameObject("Empty", pos, ' ', COLOR_WHITE, COLOR_BLACK));
    });
    game_window.Initialize();
    Button* spawn_attacker_button = new Button("Spawner", "Spawn", IVector2(0,0), 10, COLOR_BLUE, COLOR_BLACK, COLOR_BLACK, COLOR_BLUE);
    spawn_attacker_button->AddOnClickEvent([&]() -> void
    {
        AttackerTemplate temp = AttackerTemplate("Attacker", 120, COLOR_BLUE, COLOR_BLACK, 'A');
        game_objects[0][0] = make_shared<AttackerEntity>(AttackerEntity(IVector2(0,0), temp));
        game_objects[0][0]->SetOnDestroyCallback([&](IVector2 pos) -> void
        {
            game_objects[pos.GetX()][pos.GetY()] = make_shared<GameObject>(GameObject("Empty", pos, ' ', COLOR_WHITE, COLOR_BLACK));
        });
    });

    Button* spawn_attacker_button2 = new Button("Spawner", "Spawn", IVector2(0,1), 10, COLOR_BLUE, COLOR_BLACK, COLOR_BLACK, COLOR_BLUE);
    spawn_attacker_button2->AddOnClickEvent([&]() -> void
    {
        AttackerTemplate temp = AttackerTemplate("Attacker", 120, COLOR_BLUE, COLOR_BLACK, 'A');
        game_objects[0][4] = make_shared<AttackerEntity>(AttackerEntity(IVector2(0,4), temp));
        game_objects[0][4]->SetOnDestroyCallback([&](IVector2 pos) -> void
        {
            game_objects[pos.GetX()][pos.GetY()] = make_shared<GameObject>(GameObject("Empty", pos, ' ', COLOR_WHITE, COLOR_BLACK));
        });
    });
    GUIWindow attacker_selector = GUIWindow("Selector", game_width + 2, game_height + 2, IVector2(23,0));
    attacker_selector.Initialize();
    attacker_selector.AddElement(spawn_attacker_button);
    attacker_selector.AddElement(spawn_attacker_button2);
    gui_windows["Selector"] = make_shared<GUIWindow>(attacker_selector);
    current_window = gui_windows["Selector"];
}

void GameManager::Dispose()
{
    attacker_templates.clear();
    defender_templates.clear();
    gui_windows.clear();

    input_handler.Dispose();
    drawer.Dispose();
}