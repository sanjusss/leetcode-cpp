#pragma once
#include "leetcode.h"

//class Solution {
//public:
//    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//        int m = obstacleGrid.size();
//        int n = obstacleGrid[0].size();
//        int ans = 0;
//        unordered_map<int, int> q;
//        q[0] = 1;
//        while (!q.empty()) {
//            unordered_map<int, int> nexts;
//            for (auto& p : q) {
//                int i = p.first / 100;
//                int j = p.first % 100;
//                if (obstacleGrid[i][j] != 0) {
//                    continue;
//                }
//                else if (i == m - 1 && j == n - 1) {
//                    ans += p.second;
//                }
//                else {
//                    if (i + 1 < m) {
//                        nexts[(i + 1) * 100 + j] += p.second;
//                    }
//
//                    if (j + 1 < n) {
//                        nexts[i * 100 + (j + 1)] += p.second;
//                    }
//                }
//            }
//
//            q = move(nexts);
//        }
//
//        return ans;
//    }
//};

//class Solution {
//public:
//    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//        int m = obstacleGrid.size();
//        int n = obstacleGrid[0].size();
//        vector<vector<int>> dp(m, vector<int>(n));
//        if (obstacleGrid[0][0] != 0) {
//            return 0;
//        }
//        else {
//            dp[0][0] = 1;
//        }
//
//        for (int i = 0; i < m; ++i) {
//            for (int j = 0; j < n; ++j) {
//                if (obstacleGrid[i][j] != 0) {
//                    continue;
//                }
//
//                if (i > 0) {
//                    dp[i][j] += dp[i - 1][j];
//                }
//
//                if (j > 0) {
//                    dp[i][j] += dp[i][j - 1];
//                }
//            }
//        }
//
//        return dp[m - 1][n - 1];
//    }
//};

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> dp(n);
        dp[0] = (obstacleGrid[0][0] == 0 ? 1 : 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 0) {
                    if (j > 0) {
                        dp[j] += dp[j - 1];
                    }
                }
                else {
                    dp[j] = 0;
                }
            }
        }

        return dp[n - 1];
    }
};