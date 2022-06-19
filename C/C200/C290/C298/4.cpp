/*
 * @Author: sanjusss
 * @Date: 2022-06-19 10:29:03
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-19 11:09:07
 * @FilePath: \C\C200\C290\C298\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        vector<vector<int64_t>> dp(m + 1, vector<int64_t>(n + 1));
        for (auto &p : prices) {
            dp[p[0]][p[1]] = p[2];
        }

        for (int h = 1; h <= m; ++h) {
            for (int w = 1; w <= n; ++w) {
                for (int sh = h / 2; sh >= 1; --sh) {
                    dp[h][w] = max(dp[h][w], dp[sh][w] + dp[h - sh][w]);
                }

                for (int sw = w / 2; sw >= 1; --sw) {
                    dp[h][w] = max(dp[h][w], dp[h][sw] + dp[h][w - sw]);
                }
            }
        }

        return dp[m][n];
    }
};