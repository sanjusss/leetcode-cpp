/*
 * @Author: sanjusss
 * @Date: 2023-10-24 09:18:01
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-10-24 09:25:31
 * @FilePath: \1000\1100\1150\1155.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        static const constexpr int mod = 1e9 + 7;
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            int maxj = min(i * k, target);
            for (int j = maxj; j > 0; --j) {
                dp[j] = 0;
                for (int d = min(j, k); d > 0; --d) {
                    dp[j] += dp[j - d];
                    dp[j] %= mod;
                }
            }

            dp[0] = 0;
        }

        return dp[target];
    }
};

TEST(&Solution::numRollsToTarget)