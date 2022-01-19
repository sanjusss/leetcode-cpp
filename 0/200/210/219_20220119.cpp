/*
 * @Author: sanjusss
 * @Date: 2022-01-19 09:05:48
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-19 09:13:57
 * @FilePath: \0\200\210\219_20220119.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     bool containsNearbyDuplicate(vector<int>& nums, int k) {
//         unordered_map<int, int> pos;
//         int n = nums.size();
//         for (int i = 0; i < n; ++i) {
//             if (pos.count(nums[i])) {
//                 if (i - pos[nums[i]] <= k) {
//                     return true;
//                 }
//             }

//             pos[nums[i]] = i;
//         }

//         return false;
//     }
// };

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> pos;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (pos.insert(nums[i]).second == false) {
                return true;
            }

            if (i >= k) {
                pos.erase(nums[i - k]);
            }
        }

        return false;
    }
};