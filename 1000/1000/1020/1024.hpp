/*
 * @Author: sanjusss
 * @Date: 2020-10-24 11:05:37
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-10-24 11:32:58
 * @FilePath: \1000\1000\1020\1024.hpp
 */
#pragma once
#include "leetcode.h"

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        vector<int> dp(T + 1, INT_MAX - 1);
        dp[0] = 0;
        for (int i = 1; i <= T; ++i) {
            for (auto& c : clips) {
                if (i >= c[0] && i <= c[1]) {
                    dp[i] = min(dp[i], dp[c[0]] + 1);
                }
            }
        }

        return dp[T] == INT_MAX - 1 ? -1 : dp[T];
    }
};