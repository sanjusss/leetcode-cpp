/*
 * @Author: sanjusss
 * @Date: 2021-09-07 05:50:33
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-07 06:07:25
 * @FilePath: \1000\1200\1220\1221.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int balancedStringSplit(string s) {
//         int n = s.size();
//         vector<int> lcnt(n + 1);
//         vector<int> rcnt(n + 1);
//         for (int i = 0; i < n; ++i) {
//             if (s[i] == 'L') {
//                 lcnt[i + 1] = lcnt[i] + 1;
//                 rcnt[i + 1] = rcnt[i];
//             }
//             else {
//                 lcnt[i + 1] = lcnt[i];
//                 rcnt[i + 1] = rcnt[i] + 1;
//             }
//         }

//         vector<vector<int>> dp(n, vector<int>(n));
//         for (int i = n - 1; i >= 0; --i) {
//             for (int j = i + 1; j < n; ++j) {
//                 for (int k = i + 1; k < j - 1; ++k) {
//                     if (dp[i][k] > 0 && dp[k + 1][j] > 0) {
//                         dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
//                     }
//                 }

//                 if (lcnt[j + 1] - lcnt[i] == rcnt[j + 1] - rcnt[i]) {
//                     dp[i][j] = max(dp[i][j], 1);
//                 }
//             }
//         }

//         return dp[0][n - 1];
//     }
// };

class Solution {
public:
    int balancedStringSplit(string s) {
        int l = 0;
        int r = 0;
        int ans = 0;
        for (char i : s) {
            if (i == 'L') {
                ++l;
            }
            else {
                ++r;
            }

            if (l == r) {
                ++ans;
            }
        }

        return ans;
    }
};

TEST(&Solution::balancedStringSplit)