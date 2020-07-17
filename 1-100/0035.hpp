#pragma once
#include "leetcode.h"

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        int mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (nums[mid] >= target) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};