#pragma once

using namespace std;

#include <string>
#include "graphics/drawable_object/drawable_object.h"
#include "math/vector/ivector2.h"

class GameManager;

class GameObject : public DrawableObject
{
protected:
    string name;
    IVector2 position;
    char draw_character;    
    short foreground;
    short background;
public:
    GameObject(const string& _name, const IVector2& _position, char _draw_character, const short& fg, const short& bg);
    virtual ~GameObject() {};

    virtual void Update(GameManager& game_manager) = 0;
};