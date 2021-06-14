#pragma once

using namespace std;

#include <string>
#include <vector>

/**
 * Utility class to split strings by delimiter.
 */
class StringUtils
{
public:

    /**
     * Splits string as delimiter and returns the values as a vector.
     * 
     * @param s String to split
     * @param delimiter Delimier to split by
     * @return Vector of split values
     */
    static vector<string> SplitStringByDelimiter(string s, string delimiter)
    {
        vector<string> result;
        
        size_t pos = 0;
        std::string token;
        while ((pos = s.find(delimiter)) != std::string::npos) {
            token = s.substr(0, pos);
            result.push_back(token);
            s.erase(0, pos + delimiter.length());
        }
        result.push_back(s);
        return result;
    }

    /**
     * Splits string as delimiter and returns the values as a vector of integers.
     * 
     * @param s String to split
     * @param delimiter Delimier to split by
     * @return Vector of split values as integers
     */
    static vector<int> IntSplitStringByDelimiter(string s, string delimiter)
    {
        vector<int> result;
        
        size_t pos = 0;
        std::string token;
        while ((pos = s.find(delimiter)) != std::string::npos) {
            token = s.substr(0, pos);
            result.push_back(stoi(token));
            s.erase(0, pos + delimiter.length());
        }
        result.push_back(stoi(s));
        return result;
    }
};