/*
 * @Author: sanjusss
 * @Date: 2021-08-18 09:13:43
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-18 09:15:18
 * @FilePath: \jianzhioffer\57.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            if (nums[left] + nums[right] == target) {
                return { nums[left], nums[right] };
            }
            else if (nums[left] + nums[right] > target) {
                --right;
            }
            else {
                ++left;
            }
        }

        return {};
    }
};