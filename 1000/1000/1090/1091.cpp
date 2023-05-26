/*
 * @Author: sanjusss
 * @Date: 2023-05-26 08:30:38
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-05-26 08:52:57
 * @FilePath: \1000\1000\1090\1091.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }

        if (n == 1) {
            return 1;
        }

        queue<pair<int, int>> q;
        q.emplace(0, 0);
        grid[0][0] = 1;
        for (int step = 1; !q.empty(); ++step) {
            for (int qi = q.size(); qi > 0; --qi) {
                auto [i, j] = q.front();
                q.pop();
                for (int dx = -1; dx <= 1; ++dx) {
                    int x = i + dx;
                    if (x < 0 || x >= n) {
                        continue;
                    }

                    for (int dy = -1; dy <= 1; ++dy) {
                        int y = j + dy;
                        if (y < 0 || y >= n || grid[x][y] != 0) {
                            continue;
                        }

                        if (x == n - 1 && y == n - 1) {
                            return step + 1;
                        }

                        grid[x][y] = 1;
                        q.emplace(x, y);
                    }
                }
            }
        }

        return -1;
    }
};