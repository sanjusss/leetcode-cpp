/*
 * @Author: sanjusss
 * @Date: 2022-07-21 08:20:13
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-21 08:22:38
 * @FilePath: \1000\1200\1260\1260.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int next = (i * n + j + k) % total;
                int x = next / n;
                int y = next % n;
                ans[x][y] = grid[i][j];
            }
        }

        return ans;
    }
};