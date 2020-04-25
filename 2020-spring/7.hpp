#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int minTime(vector<int>& time, int m) 
    {
        int n = time.size();
        if (n <= m)
        {
            return 0;
        }

        vector<vector<int>> nums(n, vector<int>(n));
        return 0;
    }
};