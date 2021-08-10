/*
 * @Author: sanjusss
 * @Date: 2021-08-10 17:48:08
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-10 17:52:36
 * @FilePath: \jianzhioffer\03.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == i) {
                continue;
            }

            if (nums[nums[i]] == nums[i]) {
                return nums[i];
            }
            else {
                swap(nums[nums[i]], nums[i]);
            }
        }

        return 0;
    }
};