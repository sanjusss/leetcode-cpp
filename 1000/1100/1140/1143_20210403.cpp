/*
 * @Author: sanjusss
 * @Date: 2021-04-03 10:58:23
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-04-03 11:09:12
 * @FilePath: \1000\1100\1140\1143_20210403.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int size1 = text1.size();
        int size2 = text2.size();
        vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1));
        for (int i = 0; i < size1; ++i) {
            for (int j = 0; j < size2; ++j) {
                // dp[i + 1][j + 1] = max({ dp[i + 1][j + 1], dp[i + 1][j], dp[i][j + 1] ,dp[i][j] + (text1[i] == text2[j] ? 1 : 0) });
                if (text1[i] == text2[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                }
                else {
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        return dp[size1][size2];
    }
};

TEST(&Solution::longestCommonSubsequence)