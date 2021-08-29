/*
 * @Author: sanjusss
 * @Date: 2021-08-29 10:21:43
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-29 10:32:23
 * @FilePath: \C\C200\C250\C256\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        int n = nums.size();
        for (int i = k - 1; i < n; ++i) {
            ans = min(ans, nums[i] - nums[i - k + 1]);
        }

        return ans;
    }
};