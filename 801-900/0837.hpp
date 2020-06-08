#pragma once
#include "leetcode.h"

class Solution 
{
public:
    double new21Game(int N, int K, int W) 
    {
        if (K == 0)
        {
            return 1;
        }

        if (K > N)
        {
            return 0;
        }

        vector<double> dp(K + W);
        fill(dp.begin(), dp.begin() + min(K + W, N + 1), 1);
        double sum = 0;
        for (int i = 0; i < W; ++i)
        {
            sum += dp[K + i];
        }

        for (int i = K - 1; i >= 0; --i)
        {
            dp[i] = sum / W;
            sum += dp[i] - dp[i + W];
        }

        return dp[0];
    }
};