/*
 * @Author: sanjusss
 * @Date: 2022-11-10 08:49:34
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-10 09:29:18
 * @FilePath: \0\800\860\864.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        static const vector<pair<int, int>> dirs = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

        int m = grid.size();
        int n = grid[0].size();
        int kcnt = 0;
        vector<int> ki(26);
        queue<tuple<int, int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '@') {
                    q.emplace(i, j, 0);
                }
                else if (grid[i][j] >= 'a' && grid[i][j] <= 'z') {
                    ki[grid[i][j] - 'a'] = kcnt++;
                }
            }
        }

        int all = (1 << kcnt) - 1;
        vector<vector<vector<bool>>> passed(m, vector<vector<bool>>(n, vector<bool>(1 << kcnt)));
        passed[get<0>(q.front())][get<1>(q.front())][0] = true;
        for (int step = 1; !q.empty(); ++step) {
            for (int qi = q.size(); qi > 0; --qi) {
                auto [i, j, mask] = q.front();
                q.pop();
                for (auto [dx, dy] : dirs) {
                    int x = i + dx;
                    int y = j + dy;
                    int s = mask;
                    if (x < 0 || x >= m || y < 0 || y >= n) {
                        continue;
                    }
                    else if (grid[x][y] == '#') {
                        continue;
                    }
                    else if (grid[x][y] >= 'A' && grid[x][y] <= 'Z') {
                        if (!(s & (1 << ki[grid[x][y] - 'A']))) {
                            continue;
                        }
                    }
                    else if (grid[x][y] >= 'a' && grid[x][y] <= 'z') {
                        s |= 1 << ki[grid[x][y] - 'a'];
                        if (s == all) {
                            return step;
                        }
                    }

                    if (passed[x][y][s]) {
                        continue;
                    }

                    passed[x][y][s] = true;
                    q.emplace(x, y, s);
                }
            }
        }

        return -1;
    }
};