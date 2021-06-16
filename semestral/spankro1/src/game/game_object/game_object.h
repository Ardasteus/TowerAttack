#pragma once

using namespace std;

#include <string>
#include <functional>
#include "graphics/idrawable/idrawable.h"
#include "interfaces/iupdatable.h"
#include "math/vector/ivector2.h"

class GameManager;

/**
 * Base class for objects in the game (AttackerEntity and DefenderEntity)
 */
class GameObject : public IDrawable, public IUpdatable
{
protected:
    /**
     * Name of the GameObject
     */
    string name;

    /**
     * Position of the GameObject
     */
    IVector2 position;

    /**
     * Previous position of the GameObject
     */
    IVector2 previous_position;

    /**
     * Icon of this GameObject
     */
    char draw_character;

    /**
     * Foreground color
     */    
    short foreground;

    /**
     * Background color
     */
    short background;

    /**
     * Current value of update "timer"
     */
    int current_update_time;

    /**
     * Determines when/how often will this object update
     */
    int update_time;

    /**
     * A callback called when this GameObject should be destroyed
     */
    function<void(const IVector2&)> on_destroy;
    function<void(const IVector2&, const IVector2&)> on_move;
    
protected:
    void InvokeOnDestroy();
    void InvokeOnMove(const IVector2& move_to);

public:
    /**
     * Constructor with default update timer.
     * 
     * @param _name Name of the object
     * @param _position Position of the object
     * @param _draw_character Icon of the object
     * @param fg Foreground color of the object
     * @param bg Background color of the object
     */
    GameObject(const string& _name, const IVector2& _position, char _draw_character, const short& fg, const short& bg);

    /**
     * Constructor with custom update timer.
     * @param _name Name of the object
     * @param _position Position of the object
     * @param _draw_character Icon of the object
     * @param fg Foreground color of the object
     * @param bg Background color of the object
     * @param _update_time Update timer of the object
     */
    GameObject(const string& _name, const IVector2& _position, char _draw_character, const short& fg, const short& bg, int _update_time);

    /**
     * Default destructor
     */
    virtual ~GameObject() {};

    /**
     * Draws this GameObject, generally normal GameObject do not move, so should be only called once.
     * 
     * @param drawer Drawer instance to be used
     * @param offset Offset position to be used
     */
    virtual void Draw(const Drawer& drawer, const IVector2& offset) override;
    virtual void Update(GameManager&) override {};

    /**
     * Sets the on_destroy callback
     * 
     * @param func Function to be called when destroyed
     */
    void SetOnDestroyCallback(const function<void(const IVector2&)>& func);

    void SetOnMoveCallback(const function<void(const IVector2&, const IVector2&)>& func);

    /**
     * Returns the name of the object
     * 
     * @return Name of the object
     */
    const string& GetName() const;

    /**
     * Returns the position of the object
     * 
     * @return Position of the object
     */
    const IVector2& GetPosition() const;
};