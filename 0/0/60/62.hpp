#pragma once
#include "leetcode.h"

// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m, vector<int>(n));
//         fill(dp[m - 1].begin(), dp[m - 1].end(), 1);
//         for (int i = m - 2; i >= 0; --i) {
//             for (int j = n - 1; j >= 0; --j) {
//                 if (i + 1 < m) {
//                     dp[i][j] += dp[i + 1][j];
//                 }

//                 if (j + 1 < n) {
//                     dp[i][j] += dp[i][j + 1];
//                 }
//             }
//         }

//         return dp[0][0];
//     }
// };

class Solution {
public:
    int uniquePaths(int m, int n) {
        int64_t ans = 1;
        // for (int i = m + n - 2; i >= n; --i) {
        //     ans *= i;
        // }

        // for (int i = m - 1; i >= 1; --i) {
        //     ans /= i;
        // }
        for (int i = n, j = 1; j < m; ++i, ++j) {
            ans = ans * i / j;
        }

        return ans;
    }
};