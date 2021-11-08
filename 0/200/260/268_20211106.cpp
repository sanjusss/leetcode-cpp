/*
 * @Author: sanjusss
 * @Date: 2021-11-06 08:51:16
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-11-06 08:59:33
 * @FilePath: \0\200\260\268_20211106.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int n = nums.size();
//         for (int i = 0; i < n; ++i) {
//             while (nums[i] != n && nums[i] != i) {
//                 swap(nums[i], nums[nums[i]]);
//             }
//         }

//         for (int i = 0; i < n; ++i) {
//             if (nums[i] != i) {
//                 return i;
//             }
//         }

//         return n;
//     }
// };

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (n + 1) * n / 2;
        for (int i : nums) {
            sum -= i;
        }

        return sum;
    }
};