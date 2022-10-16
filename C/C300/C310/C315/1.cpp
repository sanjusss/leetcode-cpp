/*
 * @Author: sanjusss
 * @Date: 2022-10-16 10:31:59
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-16 10:35:01
 * @FilePath: \C\C300\C310\C315\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            if (-nums[left] == nums[right]) {
                return nums[right];
            }
            else if (abs(nums[left]) > abs(nums[right])) {
                ++left;
            }
            else {
                --right;
            }
        }

        return -1;
    }
};