#include "game_window.h"
#include "core/game_manager/game_manager.h"

GameWindow::GameWindow()
: GUIWindow("GameWindow", 62, 22, IVector2(0,0)),
stats_window(62, 3, IVector2(0,22)),
attacker_picker(22, 25, IVector2(63,0))
{

}

GameWindow::~GameWindow()
{
    attackers.clear();
    defenders.clear();
    path_objects.clear();
    entities_to_remove.clear();
}

void GameWindow::HandleInput(const int& key, GameManager& game_manager)
{
    attacker_picker.HandleInput(key, game_manager);
}

void GameWindow::Draw(const Drawer& drawer, const IVector2& offset)
{
    drawer.SetWindow(handle);
    if(full_redraw)
    {
        drawer.SetColor(foreground_color, background_color);
        drawer.Clear();
        drawer.DrawWindowBorder(border);
        for (int j = 0; j < GAME_HEIGHT; j++)
            for (int i = 0; i < GAME_WIDTH; i++)
                game_objects[i][j]->Draw(drawer, offset);

        full_redraw = false;
    }
    else
    {
        for(const auto& path : path_objects)
            path->Draw(drawer, offset);
        for(const auto& entity : attackers)
            entity->Draw(drawer, offset);
        for(const auto& entity : defenders)
            entity->Draw(drawer, offset);
    }
    drawer.SetColor(foreground_color, background_color);
    drawer.DrawWindowBorder(border);
    drawer.Refresh();
    stats_window.Draw(drawer, offset);
    attacker_picker.Draw(drawer, offset);
}

void GameWindow::Update(GameManager& game_manager)
{
    for(const auto& entity : defenders)
        entity->Update(game_manager);
    
    for(const auto& to_delete : entities_to_remove)
        attackers.erase(to_delete);
    entities_to_remove.clear();

    for(const auto& entity : attackers)
        entity->Update(game_manager);

    for(const auto& to_delete : entities_to_remove)
        attackers.erase(to_delete);
    entities_to_remove.clear();
}

void GameWindow::Initialize()
{
    GUIWindow::Initialize();
    stats_window.Initialize();
    attacker_picker.Initialize();
    map_game_objects['#'] = GameObject("Empty", IVector2(0,0), ' ', COLOR_WHITE, COLOR_BLACK);
    map_game_objects['^'] = GameObject("Spawner", IVector2(0,0), '^', COLOR_WHITE, COLOR_BLACK);
    map_game_objects['$'] = GameObject("End", IVector2(0,0), '$', COLOR_WHITE, COLOR_BLACK);
    map_game_objects['.'] = GameObject("Path", IVector2(0,0), '.', COLOR_WHITE, COLOR_BLACK);
    map_game_objects['x'] = GameObject("Unavailable", IVector2(0,0), 'x', COLOR_RED, COLOR_BLACK);
    tile_game_objects[TileType::Empty] = map_game_objects['#'];
    tile_game_objects[TileType::End] = map_game_objects['$'];
    tile_game_objects[TileType::Path] = map_game_objects['.'];
    tile_game_objects[TileType::Spawner] = map_game_objects['^'];
    tile_game_objects[TileType::Unavailable] = map_game_objects['x'];
    char_tile_pair['#'] = TileType::Empty;
    char_tile_pair['^'] = TileType::Spawner;
    char_tile_pair['$'] = TileType::End;
    char_tile_pair['.'] = TileType::Path;
    char_tile_pair['x'] = TileType::Unavailable;
}

void GameWindow::Initialize(GameManager& game_manager)
{
    stats_window.Initialize(game_manager);
    attacker_picker.Initialize(game_manager);
}

vector<shared_ptr<GameObject>> GameWindow::GetEntitiesInSquare(const IVector2& position, const int& radius)
{
    vector<shared_ptr<GameObject>> result;
    IVector2 left_corner = position - IVector2(radius, radius);
    int diameter = 2 * radius;
    for (int i = 0; i <= diameter; i++)
    {
        for (int j = 0; j <= diameter; j++)
        {
            IVector2 pos = left_corner + IVector2(i,j);
            if(IsEntity(pos))
                result.push_back(game_objects[pos.GetX()][pos.GetY()]);
        }
        
    }
    return result;
}

TileGameObjectPair GameWindow::GetGameObjectAtPosition(const IVector2& position)
{
    if(!IsPositionValid(position))
        return TileGameObjectPair(TileType::Unavailable, nullptr);
    int x = position.GetX();
    int y = position.GetY();
    return TileGameObjectPair(game_map_mask[x][y], game_objects[x][y]);
}

vector<shared_ptr<GameObject>> GameWindow::GetPathsNearPosition(const IVector2& position)
{
    vector<shared_ptr<GameObject>> result;
    vector<IVector2> positions;
    positions.push_back(position + IVector2(0, 1));
    positions.push_back(position + IVector2(1, 0));
    positions.push_back(position - IVector2(0, 1));
    positions.push_back(position - IVector2(1, 0));
    for (auto pos : positions)
    {
        TileType type = GetGameObjectAtPosition(pos).tile_type;
        if(type == TileType::Path || type == TileType::End || type == TileType::Spawner)
            result.push_back(game_objects[pos.GetX()][pos.GetY()]);
    }
    return result;
}

shared_ptr<AttackerEntity> GameWindow::TrySpawnAttacker(const AttackerTemplate& temp)
{
    TileGameObjectPair cell_pair = GetGameObjectAtPosition(spawn_location);
    shared_ptr<AttackerEntity> attacker = dynamic_pointer_cast<AttackerEntity>(cell_pair.game_object);
    if(cell_pair.tile_type != TileType::Spawner)
        return nullptr;
    if(attacker != nullptr)
        return nullptr;

    string name = temp.name + to_string(temp.count);
    attacker = make_shared<AttackerEntity>(spawn_location, name, temp);

    game_objects[spawn_location.GetX()][spawn_location.GetY()] = attacker;
    attackers.insert(attacker);
    return attacker;
}

shared_ptr<DefenderEntity> GameWindow::TrySpawnDefender(const IVector2& position, const DefenderTemplate& temp)
{
    if(!IsPositionValid(position) || IsEntity(position))
        return nullptr;

    TileGameObjectPair cell_pair = GetGameObjectAtPosition(position);
    if(cell_pair.tile_type != TileType::Empty)
        return nullptr;

    string name = temp.name + to_string(temp.count);
    shared_ptr<DefenderEntity> defender = make_shared<DefenderEntity>(position, name, temp);

    game_objects[position.GetX()][position.GetY()] = defender;
    defenders.insert(defender);
    return defender;
}

bool GameWindow::TryMoveEntity(const IVector2& position, const IVector2& move_to)
{
    if(!IsPositionValid(position) || !IsPositionValid(move_to))
        return false;

    if(!IsEntity(position) || IsEntity(move_to)) 
        return false;

    int pos_x = position.GetX();
    int pos_y = position.GetY();
    int dest_x = move_to.GetX();
    int dest_y = move_to.GetY();
    game_objects[dest_x][dest_y] = game_objects[pos_x][pos_y];
    shared_ptr<GameObject> replacement = make_shared<GameObject>(tile_game_objects[game_map_mask[pos_x][pos_y]]);
    replacement->SetPosition(position);
    game_objects[pos_x][pos_y] = replacement;
    return true;
}

bool GameWindow::IsEntity(const IVector2& position)
{
    if(!IsPositionValid(position))
        return false;

    TileGameObjectPair cell_pair = GetGameObjectAtPosition(position);
    shared_ptr<AttackerEntity> attacker = dynamic_pointer_cast<AttackerEntity>(cell_pair.game_object);
    shared_ptr<DefenderEntity> defender = dynamic_pointer_cast<DefenderEntity>(cell_pair.game_object);
    return attacker != nullptr || defender != nullptr;
}

bool GameWindow::IsPositionValid(const IVector2& position) const
{
    int pos_x = position.GetX();
    int pos_y = position.GetY();
    return pos_x >= 0 && pos_x < GAME_WIDTH && pos_y >= 0 && pos_y < GAME_HEIGHT;
}

void GameWindow::DeleteObjectAtPosition(const IVector2& position)
{
    if(!IsPositionValid(position))
        return;

    int pos_x = position.GetX();
    int pos_y = position.GetY();
    entities_to_remove.push_back(GetGameObjectAtPosition(position).game_object);
    shared_ptr<GameObject> replacement = make_shared<GameObject>(tile_game_objects[game_map_mask[pos_x][pos_y]]);
    replacement->SetPosition(position);
    game_objects[pos_x][pos_y] = replacement;
}

string GameWindow::LoadMap(const string& chosen_map)
{
    attackers.clear();
    defenders.clear();
    path_objects.clear();
    entities_to_remove.clear();
    fstream map;
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
                return "Map (" + chosen_map + ") failed to load: invalid size of the map. " +
                "Should be width: " + to_string(GAME_WIDTH) + " height: " + to_string(GAME_HEIGHT) + ".";
            }
            for (int i = 0; i < GAME_WIDTH; i++)
            {
                char current_char = line[i];
                if(map_game_objects.find(current_char) == map_game_objects.end())
                    return "Map (" + chosen_map + ") failed to load: Invalid character read (" + current_char + ").";

                if(current_char == '^')
                    spawn_location = IVector2(i, j);
                game_objects[i][j] = make_shared<GameObject>(map_game_objects[current_char]);
                game_map_mask[i][j] = char_tile_pair[current_char];
                game_objects[i][j]->SetPosition(IVector2(i,j));

                if(current_char == '.' || current_char == '^' || current_char == '$')
                    path_objects.push_back(game_objects[i][j]);
            }
        }
        map.close();
        full_redraw = true;
        return "";
    }

    return "Map (" + chosen_map + ") failed to load: File (./assets/maps/" + chosen_map + ") could not be opened.";
}