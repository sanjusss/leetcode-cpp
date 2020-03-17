#pragma once
#include "leetcode.h"

class Solution
{
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) 
    {
        if (jobDifficulty.size() < d)
        {
            return -1;
        }

        int size = jobDifficulty.size();
        vector<vector<int>> diff(size, vector<int>(size, 0));
        for (int i = 0; i < size; ++i)
        {
            diff[i][i] = jobDifficulty[i];
            for (int j = i + 1; j < size; ++j)
            {
                diff[i][j] = max(jobDifficulty[j], diff[i][j - 1]);
            }
        }

        vector<vector<int>> dp(d, vector<int>(size));
        //dp[i][j] = min{dp[i - 1][k] + diff[k + 1][j]} j¡¢k >= i - 1, k < j
        for (int i = 0; i < d; ++i)
        {
            if (i == 0)
            {
                for (int j = i; j < size; ++j)
                {
                    dp[i][j] = diff[i][j];
                }
            }
            else
            {
                for (int j = i; j < size; ++j)
                {
                    int value = INT_MAX;
                    for (int k = i - 1; k < j; ++k)
                    {
                        value = min(value, dp[i - 1][k] + diff[k + 1][j]);
                    }

                    dp[i][j] = value;
                }
            }
        }

        return dp[d - 1][size - 1];
    }
};