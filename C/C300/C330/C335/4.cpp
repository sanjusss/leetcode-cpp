/*
 * @Author: sanjusss
 * @Date: 2023-03-05 10:28:17
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-03-05 11:12:08
 * @FilePath: \C\C300\C330\C335\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        static constexpr int64_t mod = 1e9 + 7;
        vector<int64_t> dp(target + 1);
        dp[0] = 1;
        vector<int64_t> tmp(target + 1);
        for (auto& type : types) {
            int mark = type[1];
            int cnt = min(type[0], target / mark);
            fill(tmp.begin(), tmp.end(), (int64_t)0);
            for (int c = 1; c <= cnt; ++c) {
                int add = c * mark;
                for (int i = target - add; i >= 0; --i) {
                    tmp[i + add] += dp[i];
                    tmp[i + add] %= mod;
                }
            }

            for (int i = 1; i <= target; ++i) {
                dp[i] += tmp[i];
                dp[i] %= mod;
            }
        }

        return dp[target];
    }
};