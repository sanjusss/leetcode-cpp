#pragma once
#include "leetcode.h"

class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        int v;
        while (left <= right) {
            mid = (left + right) / 2;
            v = nums[mid];
            if (v == mid) {
                return mid;
            }

            if (v < mid) {
                if (v >= left && nums[v] == v) {
                    return v;
                }

                left = mid + 1;
            }
            else {
                if (v <= right && nums[v] == v) {
                    return v;
                }

                right = mid - 1;
            }
        }

        return -1;
    }
};