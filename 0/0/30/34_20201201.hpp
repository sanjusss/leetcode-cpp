#pragma once
#include "leetcode.h"

// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         auto pos = lower_bound(nums.begin(), nums.end(), target);
//         if (pos == nums.end() || *pos != target) {
//             return { -1, -1 };
//         }

//         auto end = upper_bound(nums.begin(), nums.end(), target);
//         return { int(pos - nums.begin()), int(end - nums.begin() - 1) };
//     }
// };

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        if (size == 0) {
            return { -1, -1 };
        }

        int left = 0;
        int right = size;
        int mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        if (left >= size || nums[left] != target) {
            return { -1, -1 };
        }

        int start = left;
        left = 0;
        right = size;
        while (left < right) {
            mid = (left + right) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        return { start, left - 1 };
    }
};