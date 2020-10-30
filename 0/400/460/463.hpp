/*
 * @Author: sanjusss
 * @Date: 2020-10-30 21:34:22
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-10-30 21:53:36
 * @FilePath: \0\400\460\463.hpp
 */
#pragma once
#include "leetcode.h"

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        static const vector<vector<int>> dirs = {
            { 1, 0 },
            { -1, 0 },
            { 0, 1 },
            { 0, -1 },
        };

        int ans = 0;
        int m = grid.size();
        if (m == 0) {
            return 0;
        }

        int n = grid[0].size();
        if (n == 0) {
            return 0;
        }

        int x;
        int y;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    continue;
                }

                ans += 4;
                for (auto& dir : dirs) {
                    x = i + dir[0];
                    y = j + dir[1];
                    if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                        --ans;
                    }
                }
            }
        }

        return ans;
    }
};