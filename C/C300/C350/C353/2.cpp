/*
 * @Author: sanjusss
 * @Date: 2023-06-25 10:25:09
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-07-09 10:36:50
 * @FilePath: \C\C300\C350\C353\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -n);
        dp[n - 1] = 0;
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] - nums[i] >= -target && nums[j] - nums[i] <= target) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[0] < 0 ? -1 : dp[0];
    }
};

TEST(&Solution::maximumJumps)