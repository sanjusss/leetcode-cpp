/*
 * @Author: sanjusss
 * @Date: 2020-10-05 07:32:13
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-10-05 09:20:55
 * @FilePath: \0\0\10\18.hpp
 */

#pragma once
#include "leetcode.h"

// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         vector<vector<int>> ans;
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         for (int i = 0; i < n; ++i) {
//             if (i > 0 && nums[i] == nums[i - 1]) {
//                 continue;
//             }

//             for (int j = i + 1; j < n; ++j) {
//                 if (j != i + 1 && nums[j] == nums[j - 1]) {
//                     continue;
//                 }

//                 for (int k = j + 1; k < n; ++k) {
//                     if (k != j + 1 && nums[k] == nums[k - 1]) {
//                         continue;
//                     }

//                     for (int l = k + 1; l < n; ++l) {
//                         if (l != k + 1 && nums[l] == nums[l - 1]) {
//                             continue;
//                         }

//                         if (nums[i] + nums[j] + nums[k] + nums[l] == target) {
//                             ans.push_back({nums[i], nums[j], nums[k], nums[l]});
//                         }
//                     }
//                 }
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (int j = i + 1; j < n; ++j) {
                if (j != i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                int val = target - nums[i] - nums[j];
                int left = j + 1;
                int right = n - 1;
                int cur;
                while (left < right) {
                    if (left != j + 1 && nums[left] == nums[left - 1]) {
                        ++left;
                        continue;
                    }

                    if (right != n - 1 && nums[right] == nums[right + 1]) {
                        --right;
                        continue;
                    }

                    int cur = nums[left] + nums[right];
                    if (cur == val) {
                        ans.push_back({ nums[i], nums[j], nums[left], nums[right] });
                        ++left;
                    }
                    else if (cur < val) {
                        ++left;
                    }
                    else {
                        --right;
                    }
                }
            }
        }

        return ans;
    }
};