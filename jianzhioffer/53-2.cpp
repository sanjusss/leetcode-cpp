/*
 * @Author: sanjusss
 * @Date: 2021-08-10 17:59:09
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-10 18:02:23
 * @FilePath: \jianzhioffer\53-2.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int n = nums.size();
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
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] > mid) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};