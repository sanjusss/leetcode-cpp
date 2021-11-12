/*
 * @Author: sanjusss
 * @Date: 2021-11-12 14:16:12
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-11-12 15:22:12
 * @FilePath: \0\300\370\375.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n, vector<int>(n));
        for (int j = 0; j < n; ++j) {
            for (int i = j - 1; i >= 0; --i) {
                dp[i][j] = INT_MAX;
                for (int k = i; k <= j; ++k) {  // 第一个猜的点
                    dp[i][j] = min(dp[i][j], max((k > i ? dp[i][k - 1] : 0), (k < j ? dp[k + 1][j] : 0)) + (k + 1));
                }
            }
        }

        return dp[0][n - 1];
    }
};

TEST(&Solution::getMoneyAmount)