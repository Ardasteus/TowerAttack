#pragma once

using namespace std;

#include <string>
#include <functional>
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
    function<void(IVector2)> onDestroy;
public:
    GameObject(const string& _name, const IVector2& _position, char _draw_character, const short& fg, const short& bg);
    virtual ~GameObject() {};

    virtual void Update(GameManager& game_manager) {};
    virtual void Draw(const Drawer& drawer, const IVector2& offset) const override;
    void SetOnDestroyCallback(function<void(IVector2)> func);
};