/*
 * @Author: sanjusss
 * @Date: 2022-12-15 09:00:58
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-15 10:00:26
 * @FilePath: \0\300\310\317.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int shortestDistance(vector<vector<int>>& grid) {
//         static const vector<pair<int, int>> dirs = { { 1, 0 }, { -1, 0 }, { 0, -1 }, { 0, 1 } };

//         int m = grid.size();
//         int n = grid[0].size();
//         int total = 0;
//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 if (grid[i][j] == 1) {
//                     ++total;
//                 }
//             }
//         }

//         int ans = INT_MAX;
//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 if (grid[i][j] != 0) {
//                     continue;
//                 }

//                 int cnt = 0;
//                 int dis = 0;
//                 vector<vector<bool>> used(m, vector<bool>(n));
//                 used[i][j] = true;
//                 queue<pair<int, int>> q;
//                 q.emplace(i, j);
//                 for (int d = 1; !q.empty(); ++d) {
//                     for (int qi = q.size(); qi > 0; --qi) {
//                         auto [x, y] = q.front();
//                         q.pop();
//                         for (auto [dx, dy] : dirs) {
//                             int nx = dx + x;
//                             int ny = dy + y;
//                             if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
//                                 continue;
//                             }

//                             if (used[nx][ny] || grid[nx][ny] == 2) {
//                                 continue;
//                             }

//                             used[nx][ny] = true;
//                             if (grid[nx][ny] == 1) {
//                                 ++cnt;
//                                 dis += d;
//                                 continue;
//                             }

//                             q.emplace(nx, ny);
//                         }
//                     }
//                 }

//                 if (cnt == total) {
//                     ans = min(ans, dis);
//                 }
//             }
//         }

//         return ans == INT_MAX ? -1 : ans;
//     }
// };

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        static const vector<pair<int, int>> dirs = { { 1, 0 }, { -1, 0 }, { 0, -1 }, { 0, 1 } };

        int m = grid.size();
        int n = grid[0].size();
        int total = 0;
        vector<vector<int>> cnt(m, vector<int>(n));
        vector<vector<int>> dis(m, vector<int>(n));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 1) {
                    continue;
                }

                ++total;
                q.emplace(i, j);
                for (int d = 1; !q.empty(); ++d) {
                    for (int qi = q.size(); qi > 0; --qi) {
                        auto [px, py] = q.front();
                        q.pop();
                        for (auto [dx, dy] : dirs) {
                            int x = px + dx;
                            int y = py + dy;
                            if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] > 0 || grid[x][y] == -total) {
                                continue;
                            }

                            grid[x][y] = -total;
                            dis[x][y] += d;
                            ++cnt[x][y];
                            q.emplace(x, y);
                        }
                    }
                }
            }
        }

        int ans = INT_MAX;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (cnt[i][j] == total) {
                    ans = min(ans, dis[i][j]);
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

TEST(&Solution::shortestDistance)