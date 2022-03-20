/*
 * @Author: sanjusss
 * @Date: 2022-03-20 10:22:01
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-03-20 10:36:07
 * @FilePath: \C\C200\C280\C285\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int prev = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (nums[i] == nums[prev]) {
                continue;
            }
            else if (nums[i] == nums[i + 1]) {
                continue;
            }

            if (nums[i] > nums[prev] && nums[i] > nums[i + 1]) {
                ++ans;
            }
            else if (nums[i] < nums[prev] && nums[i] < nums[i + 1]) {
                ++ans;
            }

            prev = i;
        }
    }
};