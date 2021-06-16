#include "map_handler.h"

using namespace std;

bool MapHandler::Load()
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

        error_message = "";
        return true;
    }
    else
    {
        error_message = "Maps could not be loaded: File (./assets/maps/map_list) could not be opened.";
        return false;
    }
}

const string& MapHandler::GetError() const
{
    return error_message;
}

const string& MapHandler::GetRandomMap()
{
    fstream map;
    random_device rand;
    mt19937 rng(rand());
    uniform_int_distribution<int> rand_dist(0, map_files.size() - 1);
    auto index = map_files.begin();
    bool has_spawner = false;
    bool has_end = false;
    advance(index, rand_dist(rng));
    return *index;
}