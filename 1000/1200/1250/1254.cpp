/*
 * @Author: sanjusss
 * @Date: 2023-06-18 12:02:13
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-06-18 12:07:51
 * @FilePath: \1000\1200\1250\1254.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        static const vector<pair<int, int>> dirs = {
            { 1, 0 },
            { -1, 0 },
            { 0, -1 },
            { 0, 1 }
        };
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 0) {
                    continue;
                }

                grid[i][j] = 1;

                int add = 1;
                q.emplace(i, j);
                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    for (auto [dx, dy] : dirs) {
                        int nx = x + dx;
                        int ny = y + dy;
                        if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                            add = 0;
                            continue;
                        }

                        if (grid[nx][ny] != 0) {
                            continue;
                        }

                        grid[nx][ny] = 1;
                        q.emplace(nx, ny);
                    }
                }

                ans += add;
            }
        }

        return ans;
    }
};