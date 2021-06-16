#pragma once

using namespace std;

#include "interfaces/iloadable.h"
#include <fstream>
#include <random>
#include <vector>

class MapHandler : public ILoadable
{
protected:
    vector<string> map_files;
public:
    bool Load() override;
    const string& GetError() const override;

    const string& GetRandomMap();
};