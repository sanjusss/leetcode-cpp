#pragma once
#include "leetcode.h"

//class Solution {
//public:
//    int minPathSum(vector<vector<int>>& grid) {
//        int m = grid.size();
//        if (m == 0) {
//            return 0;
//        }
//
//        int n = grid[0].size();
//        if (n == 0) {
//            return 0;
//        }
//
//        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
//        for (int i = 2; i <= m; ++i) {
//            dp[i][0] = INT_MAX;
//        }
//
//        if (n >= 2) {
//            fill(dp[0].begin() + 2, dp[0].end(), INT_MAX);
//        }
//
//        for (int i = 0; i < m; ++i) {
//            for (int j = 0; j < n; ++j) {
//                dp[i + 1][j + 1] = min(dp[i][j + 1], dp[i + 1][j]) + grid[i][j];
//            }
//        }
//
//        return dp[m][n];
//    }
//};

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) {
            return 0;
        }

        int n = grid[0].size();
        if (n == 0) {
            return 0;
        }

        vector<int> dp(n + 1, INT_MAX);
        for (int i = 0; i < m; ++i) {
            if (i == 0) {
                dp[0] = 0;
            }
            else {
                dp[0] = INT_MAX;
            }

            for (int j = 0; j < n; ++j) {
                dp[j + 1] = min(dp[j], dp[j + 1]) + grid[i][j];
            }
        }

        return dp[n];
    }
};