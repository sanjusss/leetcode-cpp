/*
 * @Author: sanjusss
 * @Date: 2020-10-07 09:02:18
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-10-07 10:05:08
 * @FilePath: \0\0\70\75_20201007.hpp
 */
#pragma once
#include "leetcode.h"

// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//     }
// };

// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int arr[3] = { 0 };
//         for (int i : nums) {
//             ++arr[i];
//         }

//         fill(nums.begin(), nums.begin() + arr[0], 0);
//         fill(nums.begin() + arr[0], nums.begin() + arr[0] + arr[1], 1);
//         fill(nums.begin() + arr[0] + arr[1], nums.end(), 2);
//     }
// };

// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int n = nums.size();
//         int i = 0;

//         while (i < n && nums[i] == 0) {
//             ++i;
//         }

//         for (int j = i + 1; j < n; ++j) {
//             if (nums[j] == 0) {
//                 swap(nums[i], nums[j]);
//                 ++i;
//             }
//         }

//         while (i < n && nums[i] == 1) {
//             ++i;
//         }

//         for (int j = i + 1; j < n; ++j) {
//             if (nums[j] == 1) {
//                 swap(nums[i], nums[j]);
//                 ++i;
//             }
//         }
//     }
// };

class Solution {
   public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p0 = 0;
        int p1 = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                swap(nums[i], nums[p1]);
                ++p1;
            } else if (nums[i] == 0) {
                swap(nums[i], nums[p0]);
                if (p0 < p1) {
                    swap(nums[i], nums[p1]);
                }
                
                ++p0;
                ++p1;
            }
        }
    }
};