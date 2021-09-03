/*
 * @Author: sanjusss
 * @Date: 2021-09-03 08:45:30
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-03 10:34:04
 * @FilePath: \jianzhioffer\49.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 6) {
            return n;
        }

        vector<pair<int, int>> state = {
            { 2, 0 },
            { 3, 0 },
            { 5, 0 },
        };
        vector<int> dp { { 1 } };
        int ans = 0;
        for (int i = 2; i <= n; ++i) {
            ans = INT_MAX;
            for (auto [k, j] : state) {
                ans = min(ans, k * dp[j]);
            }

            for (auto& [k, j] : state) {
                if (k * dp[j] == ans) {
                    ++j;
                }
            }

            dp.push_back(ans);
        }

        return ans;
    }
};