#pragma once
#include "leetcode.h"

class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            if (i == nums[i]) {
                return i;
            }

            if (i < nums[i]) {
                i = nums[i];
            }
            else {
                ++i;
            }
        }

        return -1;
    }
};