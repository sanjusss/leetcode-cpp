#pragma once
#include "leetcode.h"

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i0 = 0; 
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                continue;
            }

            if (i != i0) {
                nums[i0] = nums[i];
            }

            ++i0;
        }

        fill(nums.begin() + i0, nums.end(), 0);
    }
};