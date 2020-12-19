/*
 * @Author: sanjusss
 * @Date: 2020-12-13 10:38:51
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-12-13 10:51:00
 * @FilePath: \C\C200\C210\C219\3.hpp
 */
#pragma once
#include "leetcode.h"

class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<int> sums(n + 1);
        for (int i = 0; i < n; ++i) {
            sums[i + 1] = sums[i] + stones[i];
        }

        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int i = n; i > 0; --i) {
            for (int j = i + 1; j <= n; ++j) {
                dp[i][j] = max(sums[j - 1] - sums[i - 1] - dp[i][j - 1], sums[j] - sums[i] - dp[i + 1][j]);
            }
        }

        return dp[1][n];
    }
};