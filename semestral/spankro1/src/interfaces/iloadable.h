#pragma once

using namespace std;

#include <string>

class GameManager;

class ILoadable
{
protected:
    string error_message = "";
public:
    virtual bool Load() = 0;
    virtual const string& GetError() const
    {
        return error_message;
    }
};