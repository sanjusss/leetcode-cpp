/*
 * @Author: sanjusss
 * @Date: 2021-08-29 08:24:45
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-29 08:57:23
 * @FilePath: \jianzhioffer\14.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int cuttingRope(int n) {
//         vector<vector<int>> dp(n + 1, vector<int>(n  + 1));
//         for (int i = 1; i <= n; ++i) {
//             dp[i][1] = i;
//             for (int j = 2; j <= i; ++j) {
//                 for (int k = i - 1; k >= 1; --k) {
//                     dp[i][j] = max(dp[i][j], dp[k][j - 1] * (i - k));
//                 }
//             }
//         }

//         return *max_element(dp[n].begin() + 2, dp[n].end());
//     }
// };

// class Solution {
// public:
//     int cuttingRope(int n) {
//         vector<int> dp(n + 1);
//         dp[1] = 1;
//         for (int i = 2; i <= n; ++i) {
//             for (int j = 1; j < i; ++j) {
//                 dp[i] = max({ dp[i], dp[j] * (i - j), j * (i - j) });
//             }
//         }

//         return dp[n];
//     }
// };

class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 3) {
            return n - 1;
        }

        switch (n % 3) {
            case 0:
                return pow(3, n / 3);

            case 1:
                return pow(3, n / 3 - 1) * 4;

            case 2:
                return pow(3, n / 3) * 2;
        }

        return 0;
    }
};