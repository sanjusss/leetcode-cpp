/*
 * @Author: sanjusss
 * @Date: 2023-07-30 10:31:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-08-06 10:54:52
 * @FilePath: \C\C300\C350\C357\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        static const vector<pair<int, int>> dirs = {
            { 1, 0 },
            { -1, 0 },
            { 0, -1 },
            { 0, 1 },
        };
        int n = grid.size();
        vector<vector<int>> dis(n, vector<int>(n, INT_MAX));
        queue<tuple<int, int, int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    q.emplace(i, j, 0);
                    dis[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            auto [i, j, d] = q.front();
            q.pop();
            ++d;
            for (auto [dx, dy] : dirs) {
                int x = i + dx;
                int y = j + dy;
                if (x < 0 || x >= n || y < 0 || y >= n || dis[x][y] <= d) {
                    continue;
                }

                dis[x][y] = d;
                q.emplace(x, y, d);
            }
        }

        vector<vector<int>> safe(n, vector<int>(n));
        safe[0][0] = dis[0][0];
        priority_queue<tuple<int, int, int>> pq;
        pq.emplace(safe[0][0], 0, 0);
        while (!pq.empty()) {
            auto [s, i, j] = pq.top();
            pq.pop();
            if (safe[i][j] > s) {
                continue;
            }

            if (i == n - 1 && j == n - 1) {
                return s;
            }

            for (auto [dx, dy] : dirs) {
                int x = i + dx;
                int y = j + dy;
                if (x < 0 || x >= n || y < 0 || y >= n) {
                    continue;
                }

                int ds = min(dis[x][y], s);
                if (ds <= safe[x][y]) {
                    continue;
                }

                safe[x][y] = ds;
                pq.emplace(ds, x, y);
            }
        }

        return 0;
    }
};

TEST(&Solution::maximumSafenessFactor)