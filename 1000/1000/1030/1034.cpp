/*
 * @Author: sanjusss
 * @Date: 2021-12-07 16:52:00
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-12-07 17:47:14
 * @FilePath: \1000\1000\1030\1034.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        static const vector<pair<int, int>> dirs = {
            { 1, 0 },
            { -1, 0 },
            { 0, -1 },
            { 0, 1 },
        };
        int m = grid.size();
        int n = grid[0].size();
        int t = grid[row][col];
        vector<vector<bool>> passed(m, vector<bool>(n));
        passed[row][col] = true;
        queue<pair<int, int>> q;
        q.emplace(row, col);
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            if (i == 0 || i == m - 1 || j == 0 || j == n - 1 ||
                abs(grid[i + 1][j]) != t || abs(grid[i][j + 1]) != t ||
                abs(grid[i - 1][j]) != t || abs(grid[i][j - 1]) != t) {
                grid[i][j] = -grid[i][j];
            }

            for (auto [dx, dy] : dirs) {
                int x = i + dx;
                int y = j + dy;
                if (x >= 0 && x < m && y >= 0 && y < n && !passed[x][y] && grid[x][y] == t) {
                    passed[x][y] = true;
                    q.emplace(x, y);
                }
            }
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] < 0) {
                    grid[i][j] = color;
                }
            }
        }

        return grid;
    }
};