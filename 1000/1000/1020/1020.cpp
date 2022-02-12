/*
 * @Author: sanjusss
 * @Date: 2022-02-12 10:49:14
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-12 11:03:01
 * @FilePath: \1000\1000\1020\1020.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        static const vector<pair<int, int>> dirs = {
            { -1, 0 },
            { 1, 0 },
            { 0, -1 },
            { 0, 1 },
        };
        int m = grid.size();
        int n = grid[0].size();
        function<void(int, int)> dfs = [&] (int i, int j) {
            grid[i][j] = 0;
            for (auto [dx, dy] : dirs) {
                int x = i + dx;
                int y = j + dy;
                if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0) {
                    continue;
                }

                dfs(x, y);
            }
        };

        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == 1) {
                dfs(i, 0);
            }
            
            if (grid[i][n - 1] == 1) {
                dfs(i, n - 1);
            }
        }

        for (int j = n - 2; j > 0; --j) {
            if (grid[0][j] == 1) {
                dfs(0, j);
            }
            
            if (grid[m - 1][j] == 1) {
                dfs(m - 1, j);
            }
        }

        int ans = 0;
        for (int i = m - 1; i > 0; --i) {
            for (int j = n - 1; j > 0; --j) {
                if (grid[i][j] == 1) {
                    ++ans;
                }
            }
        }

        return ans;
    }
};

TEST(&Solution::numEnclaves)