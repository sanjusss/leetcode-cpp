/*
 * @Author: sanjusss
 * @Date: 2022-06-26 10:29:44
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-26 10:31:54
 * @FilePath: \C\C200\C290\C299\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j || i + j == n - 1) {
                    if (grid[i][j] == 0) {
                        return false;
                    }
                }
                else {
                    if (grid[i][j] != 0) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};