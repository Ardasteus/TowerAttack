#pragma once

using namespace std;

#include <string>
#include <vector>

class StringUtils
{
public:
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