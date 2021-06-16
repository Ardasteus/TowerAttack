#pragma once

/**
 * Interface that all classes that handle with user input have to implement
 */
class IFocusable
{
public:

    virtual void HandleInput(const int& key) = 0;
};