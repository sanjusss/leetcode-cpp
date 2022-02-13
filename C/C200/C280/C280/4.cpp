/*
 * @Author: sanjusss
 * @Date: 2022-02-13 11:18:33
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-13 11:43:45
 * @FilePath: \C\C200\C280\C280\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        static vector<int> dp(1 << 18);
        int end = 1 << (2 * numSlots);
        fill(dp.begin(), dp.begin() + end, 0);
        int n = nums.size();
        int ans = 0;
        for (int mask = 0; mask < end; ++mask) {
            int i = __builtin_popcount(mask);
            if (i >= n) {
                continue;
            }

            for (int j = 2 * numSlots - 1; j >= 0; --j) {
                int bit = 1 << j;
                if (mask & bit) {
                    continue;
                }

                dp[mask | bit] = max(dp[mask | bit], dp[mask] + (nums[i] & ((j % numSlots) + 1)));
                ans = max(ans, dp[mask | bit]);
            }
        }

        return ans;
    }
};

TEST(&Solution::maximumANDSum)