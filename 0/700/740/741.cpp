/*
 * @Author: sanjusss
 * @Date: 2022-07-10 08:50:25
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-10 10:17:49
 * @FilePath: \0\700\740\741.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int cherryPickup(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int maxStep = 2 * n - 2;
//         vector<vector<vector<int>>> dp(maxStep + 1, vector<vector<int>>(n, vector<int>(n, INT_MIN / 2)));
//         dp[0][0][0] = grid[0][0];
//         for (int step = 1; step <= maxStep; ++step) {
//             int beginX = max(step - n + 1, 0);
//             int endX = min(step, n - 1);
//             for (int x1 = beginX; x1 <= endX; ++x1) {
//                 int y1 = step - x1;
//                 if (grid[x1][y1] == -1) {
//                     continue;
//                 }

//                 for (int x2 = x1; x2 <= endX; ++x2) {
//                     int y2 = step - x2;
//                     if (grid[x2][y2] == -1) {
//                         continue;
//                     }

//                     dp[step][x1][x2] = dp[step - 1][x1][x2];
//                     if (x1 > 0) {
//                         dp[step][x1][x2] = max(dp[step][x1][x2], dp[step - 1][x1 - 1][x2]);
//                     }

//                     if (x2 > 0) {
//                         dp[step][x1][x2] = max(dp[step][x1][x2], dp[step - 1][x1][x2 - 1]);
//                     }

//                     if (x1 > 0 && x2 > 0) {
//                         dp[step][x1][x2] = max(dp[step][x1][x2], dp[step - 1][x1 - 1][x2 - 1]);
//                     }

//                     dp[step][x1][x2] += grid[x1][y1];
//                     if (x1 != x2) {
//                         dp[step][x1][x2] += grid[x2][y2];
//                     }
//                 }
//             }
//         }

//         return max(dp[maxStep][n - 1][n - 1], 0);
//     }
// };

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int maxStep = 2 * n - 2;
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        dp[0][0] = grid[0][0];
        for (int step = 1; step <= maxStep; ++step) {
            int minX = max(step - n + 1, 0);
            int maxX = min(step, n - 1);
            for (int x1 = maxX; x1 >= minX; --x1) {
                int y1 = step - x1;
                for (int x2 = maxX; x2 >= x1;--x2) {
                    int y2 = step - x2;
                    if (grid[x1][y1] == -1 || grid[x2][y2] == -1) {
                        dp[x1][x2] = INT_MIN;
                        continue;
                    }

                    if (x1 > 0) {
                        dp[x1][x2] = max(dp[x1][x2], dp[x1 - 1][x2]);
                    }

                    if (x2 > 0) {
                        dp[x1][x2] = max(dp[x1][x2], dp[x1][x2 - 1]);
                    }

                    if (x1 > 0 && x2 > 0) {
                        dp[x1][x2] = max(dp[x1][x2], dp[x1 - 1][x2 - 1]);
                    }

                    dp[x1][x2] += grid[x1][y1];
                    if (x1 != x2) {
                        dp[x1][x2] += grid[x2][y2];
                    }
                }
            }
        }

        return max(dp[n - 1][n - 1], 0);
    }
};

TEST(&Solution::cherryPickup)