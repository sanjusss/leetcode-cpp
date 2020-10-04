#pragma once

#include "leetcode.h"

class Solution {
   public:
    int specialArray(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] >= i + 1 && (i + 1 == n || i + 1 > nums[i + 1])) {
                return i + 1;
            }
        }

        return -1;
    }
};