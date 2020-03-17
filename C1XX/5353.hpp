#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int numTimesAllBlue(vector<int>& light) 
    {
        int n = light.size();
        int ans = 0;
        vector<bool> on(n, false);
        int left = 0;
        for (int i = 0; i < n; ++i)
        {
            on[light[i] - 1] = true;
            while (left < n && on[left])
            {
                ++left;
            }

            if (left > i)
            {
                ++ans;
            }
        }

        return ans;
    }
};