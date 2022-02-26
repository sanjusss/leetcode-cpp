/*
 * @Author: sanjusss
 * @Date: 2022-02-26 13:02:15
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-26 13:05:16
 * @FilePath: \2000\2000\2010\2016.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        int mine = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > mine) {
                ans = max(ans, nums[i] - mine);
            }
            else {
                mine = nums[i];
            }
        }

        return ans;
    }
};