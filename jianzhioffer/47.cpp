/*
 * @Author: sanjusss
 * @Date: 2021-08-14 09:55:14
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-14 10:03:21
 * @FilePath: \jianzhioffer\47.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int j = 1; j < n; ++j) {
            grid[0][j] += grid[0][j - 1];
        }

        for (int i = 1; i < m; ++i) {
            grid[i][0] += grid[i - 1][0];
            for (int j = 1; j < n; ++j) {
                grid[i][j] += max(grid[i][j - 1], grid[i - 1][j]);
            }
        }

        return grid[m - 1][n - 1];
    }
};