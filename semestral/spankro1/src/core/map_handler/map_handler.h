#pragma once

using namespace std;

#include "interfaces/iloadable.h"
#include <fstream>
#include <random>
#include <vector>

/**
 * Handles the loading of available maps
 */
class MapHandler : public ILoadable
{
protected:
    /**
     * vector of file names of available maps
     */
    vector<string> map_files;
public:
    /**
     * Loads available maps from a file
     * 
     * @returns true if everything loaded, false otherwise
     */
    bool Load() override;

    /**
     * Gets random file name from available map files
     * 
     * @return file name of sleected map
     */
    const string& GetRandomMap();
};