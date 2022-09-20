/*
 * @Author: sanjusss
 * @Date: 2022-09-20 08:22:57
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-09-20 09:08:13
 * @FilePath: \0\600\690\698.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     bool canPartitionKSubsets(vector<int>& nums, int k) {
//         int sum = accumulate(nums.begin(), nums.end(), 0);
//         if (sum % k != 0) {
//             return false;
//         }

//         int avg = sum / k;
//         if (*max_element(nums.begin(), nums.end()) > avg) {
//             return false;
//         }

//         int n = nums.size();
//         int allMask = (1 << n) - 1;
//         vector<int> dp(1 << n);
//         for (int mask = 1; mask <= allMask; ++mask) {
//             if (dp[mask] == 0) {
//                 int sub = 0;
//                 for (int i = 0; i < n; ++i) {
//                     if (mask & (1 << i)) {
//                         sub += nums[i];
//                     }
//                 }

//                 if (sub == avg) {
//                     dp[mask] = 1;
//                 }
//                 else {
//                     continue;
//                 }
//             }

//             int other = allMask ^ mask;
//             for (int i = n - 1; i >= 0; --i) {
//                 if (other & (1 << i)) {
//                     other ^= 1 << i;
//                 }
//                 else {
//                     break;
//                 }
//             }

//             for (int m = other; m; m = (m - 1) & other) {
//                 if (dp[m] > 0) {
//                     dp[m | mask] = dp[m] + dp[mask];
//                     break;
//                 }
//             }
//         }

//         return dp[allMask] == k;
//     }
// };

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) {
            return false;
        }

        int avg = sum / k;
        if (*max_element(nums.begin(), nums.end()) > avg) {
            return false;
        }

        int n = nums.size();
        int allMask = (1 << n) - 1;
        vector<bool> dp(1 << n);
        dp[0] = true;
        for (int mask = 0; mask < allMask; ++mask) {
            if (dp[mask] == false) {
                continue;
            }

            int sub = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    sub += nums[i];
                }
            }

            sub %= avg;
            for (int i = 0; i < n; ++i) {
                if ((mask & (1 << i)) || sub + nums[i] > avg) {
                    continue;
                }

                dp[mask | (1 << i)] = true;
            }
        }

        return dp[allMask];
    }
};

TEST(&Solution::canPartitionKSubsets)