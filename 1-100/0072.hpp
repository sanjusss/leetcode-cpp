#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int minDistance(string word1, string word2) 
    {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));//dp[i][j]表示word1前i个字符到word2前j个字符的距离
        for (int i = 0; i < n1; ++i)
        {
            dp[i + 1][0] = i + 1;
        }

        for (int j = 0; j < n2; ++j)
        {
            dp[0][j + 1] = j + 1;
        }

        for (int i = 0; i < n1; ++i)
        {
            for (int j = 0; j < n2; ++j)
            {
                if (word1[i] == word2[j])
                {
                    dp[i + 1][j + 1] = min({ dp[i][j], dp[i + 1][j] + 1, dp[i][j + 1] + 1 });
                }
                else
                {
                    dp[i + 1][j + 1] = min({ dp[i][j], dp[i + 1][j], dp[i][j + 1] }) + 1;
                }
            }
        }

        return dp[n1][n2];
    }
};