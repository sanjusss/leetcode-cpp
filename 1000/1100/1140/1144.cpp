/*
 * @Author: sanjusss
 * @Date: 2023-02-27 10:01:28
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-02-27 10:06:58
 * @FilePath: \1000\1100\1140\1144.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        vector<int> ans(2);
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int left = i > 0 ? nums[i - 1] : INT_MAX;
            int right = i + 1 < n ? nums[i + 1] : INT_MAX;
            ans[i % 2] += max(nums[i] - min(left, right) + 1, 0);
        }

        return min(ans[0], ans[1]);
    }
};