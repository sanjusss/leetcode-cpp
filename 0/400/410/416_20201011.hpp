/*
 * @Author: sanjusss
 * @Date: 2020-10-11 09:17:33
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-10-11 10:28:31
 * @FilePath: \0\400\410\416_20201011.hpp
 */
#pragma once
#include "leetcode.h"

// class Solution {
// public:
//     bool canPartition(vector<int>& nums) {
//         int sum = accumulate(nums.begin(), nums.end(), 0);
//         if (sum % 2 == 1) {
//             return false;
//         }

//         int target = sum / 2;
//         unordered_set<int> dp;
//         dp.insert(0);
//         for (int i : nums) {
//             unordered_set<int> next;
//             for (int j : dp) {
//                 next.insert(i + j);
//             }

//             for (int j : next) {
//                 dp.insert(j);
//             }
//         }

//         return dp.find(target) != dp.end();
//     }
// };

// class Solution {
// public:
//     bool canPartition(vector<int>& nums) {
//         int sum = 0;
//         for (int i : nums) {
//             sum += i;
//         }

//         if (sum % 2 == 1) {
//             return false;
//         }

//         int target = sum / 2;
//         int n = nums.size();
//         vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
//         dp[0][0] = true;
//         for (int i = 1; i <= n; ++i) {
//             dp[i][0] = true;
//             for (int j = 1; j <= target; ++j) {
//                 dp[i][j] = dp[i - 1][j] || (j - nums[i - 1] >= 0 && dp[i - 1][j - nums[i - 1]]);
//             }
//         }

//         return dp[n][target];
//     }
// };

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2 == 1) {
            return false;
        }

        int target = sum / 2;
        int n = nums.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            int v = nums[i - 1];
            if (v > target) {
                return false;
            }

            dp[i][v] = true;
            for (int j = v + 1; j <= target; ++j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - v];
            }
        }

        return dp[n][target];
    }
};