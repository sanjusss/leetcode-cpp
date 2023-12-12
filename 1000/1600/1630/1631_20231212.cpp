/*
 * @Author: sanjusss
 * @Date: 2023-12-12 10:35:49
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-12-12 10:53:39
 * @FilePath: \1000\1600\1630\1631_20231212.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        static const vector<pair<int, int>> sc_dirs = {
            { 1, 0 },
            { -1, 0 },
            { 0, -1 },
            { 0, 1 },
        };
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> efforts(m, vector<int>(n, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> q;
        q.emplace(0, 0, 0);
        efforts[0][0] = 0;
        while (!q.empty()) {
            auto [e, i, j] = q.top();
            q.pop();
            if (e > efforts[i][j]) {
                continue;
            }
            else if (i == m - 1 && j == n - 1) {
                return e;
            }

            for (auto [dx, dy] : sc_dirs) {
                int x = i + dx;
                int y = j + dy;
                if (x < 0 || x >= m || y < 0 || y >= n) {
                    continue;
                }

                int nxt = max(e, abs(heights[i][j] - heights[x][y]));
                if (nxt >= efforts[x][y]) {
                    continue;
                }

                efforts[x][y] = nxt;
                q.emplace(nxt, x, y);
            }
        }

        return -1;
    }
};