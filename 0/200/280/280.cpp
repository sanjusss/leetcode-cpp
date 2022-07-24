/*
 * @Author: sanjusss
 * @Date: 2022-06-26 16:22:00
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-26 16:35:33
 * @FilePath: \0\200\280\280.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     void wiggleSort(vector<int>& nums) {
//         vector<int> temp = nums;
//         sort(temp.begin(), temp.end());
//         int n = nums.size();
//         int half = (n + 1) / 2;
//         for (int i = 0; i < n; ++i) {
//             if (i % 2 == 0) {
//                 nums[i] = temp[i / 2];
//             }
//             else {
//                 nums[i] = temp[half + i / 2];
//             }
//         }
//     }
// };

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (i % 2 == 1) {
                if (nums[i - 1] > nums[i]) {
                    swap(nums[i - 1], nums[i]);
                }
            }
            else {
                if (nums[i - 1] < nums[i]) {
                    swap(nums[i - 1], nums[i]);
                }
            }
        }
    }
};