/*
 * @Author: sanjusss
 * @Date: 2022-12-11 10:19:23
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-11 10:44:36
 * @FilePath: \C\C300\C320\C323\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n);
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            int64_t v = (int64_t)nums[i] * nums[i];
            auto p = prev(upper_bound(nums.begin() + i + 1, nums.end(), v));
            if (*p != v) {
                dp[i] = 1;
            }
            else {
                dp[i] = dp[p - nums.begin()] + 1;
            }

            ans = max(ans, dp[i]);
        }

        return ans >= 2 ? ans : -1;
    }
};