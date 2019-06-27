#pragma once
#include "leetcode.h"

class Solution 
{
public:
    vector<vector<string>> groupStrings(vector<string>& strings) 
    {
        map<string, vector<string>> groups;
        for (string i : strings)
        {
            groups[key(i)].push_back(i);
        }

        vector<vector<string>> results;
        for (auto i : groups)
        {
            results.push_back(i.second);
        }

        return results;
    }

private:
    string key(string value)
    {
        string res;
        if (value.empty())
        {
            return res;
        }

        char a = value[0];
        res += 'a';
        int length = value.length();
        for (int i = 1; i < length; ++i)
        {
            char c = 'a' + value[i] - a;
            if (c < 'a')
            {
                c += 26;
            }

            res += c;
        }

        return res;
    }
};