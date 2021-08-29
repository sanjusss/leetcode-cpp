/*
 * @Author: sanjusss
 * @Date: 2021-08-29 10:22:01
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-29 12:40:55
 * @FilePath: \C\C200\C250\C256\3.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int minSessions(vector<int>& tasks, int sessionTime) {
//         int n = tasks.size();
//         int end = 1 << n;
//         vector<int> times(end);
//         for (int mask = 1; mask < end; ++mask) {
//             int j = __builtin_ctz(mask);
//             times[mask] = times[mask - (1 << j)] + tasks[j]; 
//         }

//         vector<int> dp(end, INT_MAX);
//         dp[0] = 0;
//         for (int i = 1; i < end; ++i) {
//             for (int j = 0; j < i; ++j) {
//                 if (((i ^ j) | i) == i && times[i ^ j] <= sessionTime) {
//                     dp[i] = min(dp[i], dp[j] + 1);
//                 }
//             }
//         }

//         return dp[end - 1];
//     }
// };

class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        int end = 1 << n;
        vector<int> times(end);
        for (int mask = 1; mask < end; ++mask) {
            int j = __builtin_ctz(mask);
            times[mask] = times[mask - (1 << j)] + tasks[j]; 
        }

        vector<int> dp(end, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i < end; ++i) {
            for (int j = i; j > 0; j = i & (j - 1)) {
                if (times[j] <= sessionTime) {
                    dp[i] = min(dp[i], dp[i - j] + 1);
                }
            }
        }

        return dp[end - 1];
    }
};

TEST(&Solution::minSessions)