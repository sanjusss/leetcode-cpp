/*
 * @Author: sanjusss
 * @Date: 2023-02-26 10:52:12
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-02-26 11:58:30
 * @FilePath: \C\C300\C330\C334\4.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int minimumTime(vector<vector<int>>& grid) {
//         if (grid[0][1] > 1 && grid[1][0] > 1) {
//             return -1;
//         }

//         int m = grid.size();
//         int n = grid[0].size();
//         vector<vector<int>> ans = grid;
//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 grid[i][j] = (grid[i][j] % 2) == ((i + j) % 2) ? grid[i][j] : grid[i][j] + 1;
//                 ans[i][j] = grid[i][j];
//                 int s = INT_MAX;
//                 if (i > 0) {
//                     s = min(ans[i - 1][j] + 1, s);
//                 }

//                 if (j > 0) {
//                     s = min(ans[i][j - 1] + 1, s);
//                 }

//                 if (s != INT_MAX) {
//                     ans[i][j] = max(ans[i][j], s);
//                 }
//             }
//         }

//         static const vector<pair<int, int>> dirs = {
//             { 1, 0 },
//             { -1, 0 },
//             { 0, 1 },
//             { 0, -1 }
//         };
//         queue<pair<int, int>> q;
//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 q.emplace(i, j);
//                 while (!q.empty()) {
//                     auto [x, y] = q.front();
//                     q.pop();
//                     for (auto [dx, dy] : dirs) {
//                         int u = x + dx;
//                         int v = y + dy;
//                         if (u < 0 || u >= m || v < 0 || v >= n) {
//                             continue;
//                         }

//                         if (ans[x][y] + 1 >= ans[u][v] || ans[u][v] == grid[u][v]) {
//                             continue;
//                         }

//                         ans[u][v] = max(ans[x][y] + 1, grid[u][v]);
//                         q.emplace(u, v);
//                     }
//                 }
//             }
//         }

//         return ans[m - 1][n - 1];
//     }
// };

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                grid[i][j] = (grid[i][j] % 2) == ((i + j) % 2) ? grid[i][j] : grid[i][j] + 1;
                ans[i][j] = grid[i][j];
                int s = INT_MAX;
                if (i > 0) {
                    s = min(ans[i - 1][j] + 1, s);
                }

                if (j > 0) {
                    s = min(ans[i][j - 1] + 1, s);
                }

                if (s != INT_MAX) {
                    ans[i][j] = max(ans[i][j], s);
                }
            }
        }

        static const vector<pair<int, int>> dirs = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (auto [dx, dy] : dirs) {
                    int u = i + dx;
                    int v = j + dy;
                    if (u < 0 || u >= m || v < 0 || v >= n) {
                        continue;
                    }

                    if (ans[i][j] + 1 >= ans[u][v] || ans[u][v] == grid[u][v]) {
                        continue;
                    }

                    q.emplace(max(ans[i][j] + 1, grid[u][v]), u, v);
                }
            }
        }

        while (!q.empty()) {
            auto [s, i, j] = q.top();
            q.pop();
            if (ans[i][j] <= s) {
                continue;
            }

            ans[i][j] = s;
            for (auto [dx, dy] : dirs) {
                int u = i + dx;
                int v = j + dy;
                if (u < 0 || u >= m || v < 0 || v >= n) {
                    continue;
                }

                if (s + 1 >= ans[u][v] || ans[u][v] == grid[u][v]) {
                    continue;
                }

                int a = max(s + 1, grid[u][v]);
                q.emplace(a, u, v);
            }
        }

        return ans[m - 1][n - 1];
    }
};

TEST(&Solution::minimumTime)