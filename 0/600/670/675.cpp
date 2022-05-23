/*
 * @Author: sanjusss
 * @Date: 2022-05-23 08:47:33
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-05-23 09:20:27
 * @FilePath: \0\600\670\675.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        map<int, pair<int, int>> pts;
        int m = forest.size();
        int n = forest[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (forest[i][j] > 1) {
                    pts[forest[i][j]] = make_pair(i, j);
                }
            }
        }

        static const vector<pair<int, int>> dirs = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

        int ans = 0;
        int previ = 0;
        int prevj = 0;
        deque<pair<int, int>> q;
        for (auto& [_, pt] : pts) {
            auto [i, j] = pt;
            bool success = false;
            q.emplace_back(previ, prevj);
            auto f = forest;
            f[previ][prevj] = 0;
            while (!q.empty()) {
                for (int k = q.size(); k > 0; --k) {
                    auto [x, y] = q.front();
                    q.pop_front();
                    if (x == i && y == j) {
                        success = true;
                        break;
                    }

                    for (auto [dx, dy] : dirs) {
                        int nx = x + dx;
                        int ny = y + dy;
                        if (nx < 0 || nx >= m || ny < 0 || ny >= n || f[nx][ny] == 0) {
                            continue;
                        }

                        q.emplace_back(nx, ny);
                        f[nx][ny] = 0;
                    }
                }

                if (success) {
                    break;
                }
                else {
                    ++ans;
                }
            }

            if (!success) {
                return -1;
            }

            q.clear();
            previ = i;
            prevj = j;
        }

        return ans;
    }
};

TEST(&Solution::cutOffTree)