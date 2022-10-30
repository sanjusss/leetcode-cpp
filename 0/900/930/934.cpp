/*
 * @Author: sanjusss
 * @Date: 2022-10-25 09:15:47
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-25 09:31:21
 * @FilePath: \0\900\930\934.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        static const vector<pair<int, int>> dirs = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q1;
        for (int i = 0; i < m && q1.empty(); ++i) {
            for (int j = 0; j < n && q1.empty(); ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 2;
                    q1.emplace(i, j);
                }
            }
        }

        queue<pair<int, int>> q0;
        while (!q1.empty()) {
            auto [i, j] = q1.front();
            q1.pop();
            for (auto [dx, dy] : dirs) {
                int x = i + dx;
                int y = j + dy;
                if (x < 0 || x >= m || y < 0 || y >= n) {
                    continue;
                }

                if (grid[x][y] == 1) {
                    grid[x][y] = 2;
                    q1.emplace(x, y);
                }
                else if (grid[x][y] == 0) {
                    grid[x][y] = -1;
                    q0.emplace(x, y);
                }
            }
        }

        int ans = 0;
        while (!q0.empty()) {
            ++ans;
            for (int k = q0.size(); k > 0; --k) {
                auto [i, j] = q0.front();
                q0.pop();
                for (auto [dx, dy] : dirs) {
                    int x = i + dx;
                    int y = j + dy;
                    if (x < 0 || x >= m || y < 0 || y >= n) {
                        continue;
                    }

                    if (grid[x][y] == 1) {
                        return ans;
                    }
                    else if (grid[x][y] == 0) {
                        grid[x][y] = -1;
                        q0.emplace(x, y);
                    }
                }
            }
        }

        return 0;
    }
};