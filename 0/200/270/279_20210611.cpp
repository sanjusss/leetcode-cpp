/*
 * @Author: sanjusss
 * @Date: 2021-06-11 11:39:56
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-11 11:49:46
 * @FilePath: \0\200\270\279_20210611.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX / 2);
        dp[0] = 0;
        for (int i = sqrt(n + 1); i > 0; --i) {
            int v = i * i;
            for (int j = v; j <= n; ++j) {
                dp[j] = min(dp[j], dp[j - v] + 1);
            }
        }

        return dp[n];
    }
};

TEST(&Solution::numSquares)