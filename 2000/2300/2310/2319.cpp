/*
 * @Author: sanjusss
 * @Date: 2023-01-31 09:09:08
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-31 09:11:15
 * @FilePath: \2000\2300\2310\2319.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i == j || i + j == n - 1) != (grid[i][j] != 0)) {
                    return false;
                }
            }
        }

        return true;
    }
};