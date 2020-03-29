#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int findLucky(vector<int>& arr) 
    {
        map<int, int> cs;
        for (int i : arr)
        {
            ++cs[i];
        }

        for (auto i = cs.rbegin(); i != cs.rend(); ++i)
        {
            if (i->first == i->second)
            {
                return i->first;
            }
        }

        return -1;
    }
};