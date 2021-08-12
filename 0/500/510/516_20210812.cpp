/*
 * @Author: sanjusss
 * @Date: 2021-08-12 09:34:37
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-12 09:41:50
 * @FilePath: \0\500\510\516_20210812.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; ++j) {
                dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
                if (s[i] == s[j]) {
                    dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 2);
                }
            }
        }

        return dp[0][n - 1];
    }
};

TEST(&Solution::longestPalindromeSubseq)