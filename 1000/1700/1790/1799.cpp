/*
 * @Author: sanjusss
 * @Date: 2022-12-22 08:43:57
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-22 08:49:36
 * @FilePath: \1000\1700\1790\1799.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxScore(vector<int>& nums) {
        int m = nums.size();
        int endMask = 1 << m;
        vector<int> dp(1 << m);
        for (int mask = 0; mask < endMask; ++mask) {
            int cnt = __builtin_popcount(mask);
            if (cnt % 2 != 0) {
                continue;
            }

            int factor = cnt / 2 + 1;
            for (int i = 0; i < m; ++i) {
                if (mask & (1 << i)) {
                    continue;
                }

                for (int j = i + 1; j < m; ++j) {
                    if (mask & (1 << j)) {
                        continue;
                    }

                    dp[mask + (1 << i) + (1 << j)] =
                        max(dp[mask + (1 << i) + (1 << j)], dp[mask] + gcd(nums[i], nums[j]) * factor);
                }
            }
        }

        return dp.back();
    }
};