#pragma once

using namespace std;

#include <string>
#include <vector>

/**
 * Header only utility class to split strings by delimiter.
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
    static vector<string> SplitStringByDelimiter(const string& to_split, const string& delimiter)
    {
        vector<string> result;
        string s = to_split;
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
    static vector<int> IntSplitStringByDelimiter(const string& to_split, const string& delimiter)
    {
        vector<int> result;
        string s = to_split;
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