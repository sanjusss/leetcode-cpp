/*
 * @Author: sanjusss
 * @Date: 2023-06-05 09:01:27
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-06-05 09:04:20
 * @FilePath: \2000\2400\2460\2460.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] == nums[i]) {
                nums[i - 1] *= 2;
                nums[i] = 0;
            }
        }

        int len = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) {
                nums[len++] = nums[i];
            }
        }

        fill(nums.begin() + len, nums.end(), 0);
        return nums;
    }
};