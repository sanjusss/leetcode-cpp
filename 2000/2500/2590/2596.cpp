/*
 * @Author: sanjusss
 * @Date: 2023-09-13 09:03:31
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-09-13 09:25:49
 * @FilePath: \2000\2500\2590\2596.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int, int>> path(n * n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                path[grid[i][j]] = { i, j };
            }
        }

        for (int i = n * n - 1; i > 0; --i) {
            auto [a, b] = path[i];
            auto [c, d] = path[i - 1];
            int dx = abs(a - c);
            int dy = abs(b - d);
            if ((dx == 2 && dy == 1) || (dx == 1 && dy == 2)) {
                continue;
            }
            else {
                return false;
            }
        }

        return grid[0][0] == 0;
    }
};