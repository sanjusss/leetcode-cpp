#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;

        for (int i = 1; i <= amount; ++i)
        {
            int minCost = INT_MAX;
            for (auto j : coins)
            {
                int last = i - j;
                if (last >= 0 &&
                    dp[last] >= 0)
                {
                    minCost = min(minCost, dp[last]);
                }
            }
            
            if (minCost != INT_MAX)
            {
                dp[i] = minCost + 1;
            }
        }

        return dp[amount];
    }
};