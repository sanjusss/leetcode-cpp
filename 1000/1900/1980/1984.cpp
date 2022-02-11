/*
 * @Author: sanjusss
 * @Date: 2022-02-11 13:58:13
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-11 13:59:51
 * @FilePath: \1000\1900\1980\1984.cpp
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