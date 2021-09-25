/*
 * @Author: sanjusss
 * @Date: 2021-09-25 09:18:22
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-25 09:22:12
 * @FilePath: \0\500\580\583.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
                if (word1[i] == word2[j]) {
                    dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
                }
            }
        }

        return m + n - dp[m][n] * 2;
    }
};

TEST(&Solution::minDistance)