#pragma once
#include "leetcode.h"

class Solution 
{
public:
    vector<string> getFolderNames(vector<string>& names) 
    {
        unordered_map<string, int> exists;
        for (auto& i : names)
        {
            int& cur = exists[i];
            if (cur == 0)
            {
                cur = 1;
            }
            else
            {
                while (exists.find(i + "(" + to_string(cur) + ")") != exists.end())
                {
                    ++cur;
                }

                i += "(" + to_string(cur) + ")";
                exists[i] = 1;
            }
        }

        return names;
    }
};