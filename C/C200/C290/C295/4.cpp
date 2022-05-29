/*
 * @Author: sanjusss
 * @Date: 2022-05-29 10:27:41
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-05-29 11:51:06
 * @FilePath: \C\C200\C290\C295\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        static const vector<pair<int, int>> dirs = {
            { 1, 0 },
            { -1, 0 },
            { 0, 1 },
            { 0, -1 }
        };
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> inQ(m, vector<int>(n, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> q;
        inQ[0][0] = 0;
        q.emplace(0, 0, 0); // 已移除次数、x、y
        while (!q.empty()) {
            auto [c, i, j] = q.top();
            q.pop();
            if (i == m - 1 && j == n - 1) {
                return c;
            }

            for (auto [dx, dy] : dirs) {
                int x = i + dx;
                int y = j + dy;
                if (x < 0 || x >= m || y < 0 || y >= n) {
                    continue;
                }

                int nc = c + grid[x][y];
                if (nc < inQ[x][y]) {
                    inQ[x][y] = nc;
                    q.emplace(nc, x, y);
                }
            }
        }

        return -1;
    }
};