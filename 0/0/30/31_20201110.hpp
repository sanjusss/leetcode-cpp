#pragma once
#include "leetcode.h"

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for (int i = nums.size() - 1; i > 0; --i) {
            if (nums[i] <= nums[i - 1]) {
                continue;
            }

            int j = nums.size() - 1;
            while (nums[j] <= nums[i - 1]) {
                --j;
            }

            swap(nums[j], nums[i - 1]);
            reverse(nums.begin() + i, nums.end());
            return;
        }

        reverse(nums.begin(), nums.end());
    }
};