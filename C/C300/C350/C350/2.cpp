/*
 * @Author: sanjusss
 * @Date: 2023-06-18 10:29:03
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-06-18 10:36:52
 * @FilePath: \C\C300\C350\C350\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = INT_MAX;
        for (int i = 1; i < n; ++i) {
            ans = min(ans, nums[i] - nums[i - 1]);
        }

        return ans;
    }
};