#pragma once

using namespace std;

#include <string>

class GameManager;

/**
 * Interface implemented by all services that load data.
 */
class ILoadable
{
protected:
    /**
     * Error message generated if something goes wrong.
     */
    string error_message = "";
public:
    /**
     * Loads data from files.
     * 
     * @return Whether or not the data was loaded properly.
     */
    virtual bool Load() = 0;

    /**
     * Returns the error generated during loading. Empty if nothing failed.
     * 
     * @return The error message 
     */
    virtual const string& GetError() const
    {
        return error_message;
    }
};