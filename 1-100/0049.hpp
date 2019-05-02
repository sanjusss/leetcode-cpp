#pragma once
#include "leetcode.h"

class Solution 
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string>> vs;
        string temp;
        for (const string& i : strs)
        {
            temp = i;
            sort(temp.begin(), temp.end());
            vs[temp].push_back(i);
        }

        vector<vector<string>> lines;
        for (const auto& i : vs)
        {
            lines.push_back(i.second);
        }

        return lines;
    }
};