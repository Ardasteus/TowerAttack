#pragma once

using namespace std;

#include "game/window/game_window.h"
#include "game/game_object/game_object.h"
#include "ui/window/gui_window.h"
#include "ui/controls/gui_object/gui_object.h"
#include "game/attacker_entity/attacker_template.h"
#include "game/defender_entity/defender_template.h"
#include "core/input_handler/input_handler.h"
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <set>

struct DefenderTemplateComparator
{
    bool operator() (const DefenderTemplate& left, const DefenderTemplate& right)
    {
        return left.name < right.name;
    }
};

struct AttackerTemplateComparator
{
    bool operator() (const AttackerTemplate& left, const AttackerTemplate& right)
    {
        return left.name < right.name;
    }
};

class GameManager
{
private:
    int game_width;
    int game_height; 
    mutable vector<vector<shared_ptr<GameObject>>> game_objects;
    set<AttackerTemplate, AttackerTemplateComparator> attacker_templates;
    set<DefenderTemplate, DefenderTemplateComparator> defender_templates;

    mutable shared_ptr<GameWindow> game_window;
    mutable map<string, shared_ptr<GUIWindow>> gui_windows;
    mutable shared_ptr<GUIWindow> current_window;
    mutable bool show_game = false;
    Drawer drawer;
    InputHandler input_handler;
public:
    GameManager();

    void Run();
    vector<shared_ptr<GameObject>> GetGameObjectsInSquare(IVector2 position, int radius) const;
    shared_ptr<GameObject> GetGameObjectAtPosition(IVector2 position) const;
    void Initialize();
    void Draw() const;
    void Update();
    void Dispose();
};  