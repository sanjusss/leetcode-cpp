#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        vector<int> dp(366 + 30);
        vector<bool> out(366);
        for (int i : days)
        {
            out[i] = true;
        }

        for (int i = 365; i >= 1; --i)
        {
            if (out[i])
            {
                dp[i] = min({ dp[i + 1] + costs[0], dp[i + 7] + costs[1], dp[i + 30] + costs[2] });
            }
            else
            {
                dp[i] = dp[i + 1];
            }
        }

        return dp[1];
    }
};