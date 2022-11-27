/*
 * @Author: sanjusss
 * @Date: 2022-11-27 10:01:52
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-27 10:10:05
 * @FilePath: \1000\1700\1750\1752.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     bool check(vector<int>& nums) {
//         auto target = nums;
//         sort(target.begin(), target.end());
//         int n = nums.size();
//         for (int i = 0; i < n; ++i) {
//             bool success = true;
//             for (int j = 0; j < n; ++j) {
//                 if (target[j] != nums[(j + i) % n]) {
//                     success = false;
//                     break;
//                 }
//             }

//             if (success) {
//                 return true;
//             }
//         }

//         return false;
//     }
// };

class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) {
                if (++cnt == 2) {
                    return false;
                }
            }
        }

        return cnt == 0 || nums.back() <= nums.front();
    }
};