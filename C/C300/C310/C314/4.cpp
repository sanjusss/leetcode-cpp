/*
 * @Author: sanjusss
 * @Date: 2022-10-09 10:59:58
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-09 11:30:29
 * @FilePath: \C\C300\C310\C314\4.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int numberOfPaths(vector<vector<int>>& grid, int k) {
//         static constexpr int mod = 1e9 + 7;
//         int m = grid.size();
//         int n = grid[0].size();
//         vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k)));
//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 if (i == 0 && j == 0) {
//                     dp[i][j][grid[i][j] % k] = 1;
//                     continue;
//                 }

//                 for (int t = 0; t < k; ++t) {
//                     if (i > 0) {
//                         dp[i][j][(grid[i][j] + t) % k] += dp[i - 1][j][t];
//                         dp[i][j][(grid[i][j] + t) % k] %= mod;
//                     }

//                     if (j > 0) {
//                         dp[i][j][(grid[i][j] + t) % k] += dp[i][j - 1][t];
//                         dp[i][j][(grid[i][j] + t) % k] %= mod;
//                     }
//                 }
//             }
//         }

//         return dp[m - 1][n - 1][0];
//     }
// };

class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        static constexpr int mod = 1e9 + 7;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> cur(n + 1, vector<int>(k));
        vector<vector<int>> prev(n + 1, vector<int>(k));
        for (int i = 0; i < m; ++i) {
            swap(cur, prev);
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) {
                    cur[j + 1][grid[i][j] % k] = 1;
                    continue;
                }

                for (int t = 0; t < k; ++t) {
                    int ki = (grid[i][j] + t) % k;
                    cur[j + 1][ki] = 0;
                    cur[j + 1][ki] += prev[j + 1][t];
                    cur[j + 1][ki] %= mod;
                    cur[j + 1][ki] += cur[j][t];
                    cur[j + 1][ki] %= mod;
                }
            }
        }

        return cur[n][0];
    }
};

TEST(&Solution::numberOfPaths)