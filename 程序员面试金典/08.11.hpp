#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int waysToChange(int n) 
    {
        int mod = 1000000007;
        vector<int> coins = { 25, 10, 5, 1 };
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int coin : coins)
        {
            for (int i = coin; i <= n; ++i)
            {
                dp[i] = (dp[i] + dp[i - coin]) % mod;
            }
        }

        return dp[n];
    }
};