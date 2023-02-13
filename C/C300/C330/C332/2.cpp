/*
 * @Author: sanjusss
 * @Date: 2023-02-12 10:35:50
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-02-12 10:42:32
 * @FilePath: \C\C300\C330\C332\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());

        int64_t ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            auto end = nums.begin() + i;
            auto left = lower_bound(nums.begin(), end, lower - nums[i]);
            auto right = upper_bound(nums.begin(), end, upper - nums[i]);
            ans += (right - left);
        }

        return ans;
    }
};