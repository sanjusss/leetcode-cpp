#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int minTaps(int n, vector<int>& ranges) 
    {
        vector<int> endIndex(n + 1, 0);
        for (int i = 0; i <= n; ++i)
        {
            if (ranges[i] == 0)
            {
                continue;
            }

            int start = max(0, i - ranges[i]);
            int end = min(n, i + ranges[i]);
            for (int j = start; j < end; ++j)
            {
                endIndex[j] = max(endIndex[j], end);
            }
        }

        int i = 0;
        int ans = 0;
        while (i < n)
        {
            if (endIndex[i] == 0)
            {
                return -1;
            }
            else
            {
                i = endIndex[i];
                ++ans;
            }
        }

        return ans;
    }
};