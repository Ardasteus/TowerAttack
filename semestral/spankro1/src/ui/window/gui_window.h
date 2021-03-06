#pragma once

using namespace std;

#include "graphics/window/base_window.h"
#include "ui/controls/gui_object/gui_object.h"
#include "ui/controls/focusable_gui_object/focusable_gui_object.h"
#include "interfaces/ifocusable.h"
#include <list>
#include <memory>

class GameManager;

/**
 * Window class that holds GUIObject instances and passes user input to FocusableGUIObject instances
 */
class GUIWindow : public BaseWindow, public IFocusable
{
protected:
    /**
     * List of UI objects in this window
     */
    list<shared_ptr<GUIObject>> gui_elements;

    /**
     * Vector of Focusable UI objects in this window
     */
    vector<shared_ptr<FocusableGUIObject>> focusable_elements;

    /**
     * Index of currently focused FocusableGUIObject
     */
    int focused_element;

    /**
     * Name of the window
     */
    string name;
public:
    /**
     * Default constructor
     */
    GUIWindow();

    /**
     * Constructor with default border
     * 
     * @param _name Name of the window
     * @param width Width of the window
     * @param height Height of the window
     * @param position Position of the window
     */
    GUIWindow(const string& _name, const int& width, const int& height, const IVector2& position);

    /**
     * Constructor with custom border
     * 
     * @param _name Name of the window
     * @param width Width of the window
     * @param height Height of the window
     * @param position Position of the window
     * @param border Border of the window
     */
    GUIWindow(const string& _name, const int& width, const int& height, const IVector2& position, const WindowBorder& border);

    /**
     * Default destructor
     */
    ~GUIWindow();

    /**
     * Sets the curren window of the Drawer instance to this window, draws its border and draws all GUIObjects.
     * 
     * @param drawer Drawer instance to be used
     * @param offset Offset to be used
     */
    virtual void Draw(const Drawer& drawer, const IVector2& offset) override;

    /**
     * Handles user input, up/down arrows cycle between focusable UI objects, if anything else is pressed it gets passed down to currently focused object.
     * 
     * @param key Key code
     * @param game_manager GameManager instance to use
     */
    virtual void HandleInput(const int& key, GameManager& game_manager);

    /**
     * Adds new GUIObject to this class, if it also a FocusableGUIObject adds it to the vector of those as well.
     * 
     * @param element GUIObject to add
     */
    void AddElement(shared_ptr<GUIObject> element);
};