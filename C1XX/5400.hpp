#pragma once
#include "leetcode.h"

class Solution 
{
public:
    string destCity(vector<vector<string>>& paths) 
    {
        unordered_set<string> src;
        unordered_set<string> des;
        for (auto& p : paths)
        {
            src.insert(p[0]);
            des.insert(p[1]);
        }

        for (auto& i : des)
        {
            if (src.find(i) == src.end())
            {
                return i;
            }
        }

        return string();
    }
};