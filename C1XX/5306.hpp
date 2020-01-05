#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int minInsertions(string s) 
    {
        int size = s.size();
        //求s的最长回文子序列
        //dp[i][j]表示字符串s[i,j]的最长回文子串长度。
        vector<vector<int>> dp(size, vector<int>(size, 0));
        for (int i = size - 1; i >= 0; --i)
        {
            dp[i][i] = 1;
            for (int j = i + 1; j < size; ++j)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return size - dp[0][size - 1];
    }
};