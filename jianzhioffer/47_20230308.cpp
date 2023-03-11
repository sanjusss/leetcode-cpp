/*
 * @Author: sanjusss
 * @Date: 2023-03-08 08:35:33
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-03-08 08:38:39
 * @FilePath: \jianzhioffer\47_20230308.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int pre = 0;
                if (i > 0) {
                    pre = max(pre, grid[i - 1][j]);
                }

                if (j > 0) {
                    pre = max(pre, grid[i][j - 1]);
                }

                grid[i][j] += pre;
            }
        }

        return grid[m - 1][n - 1];
    }
};