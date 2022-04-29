/*
 * @Author: sanjusss
 * @Date: 2022-04-27 08:55:51
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-04-27 10:17:27
 * @FilePath: \0\400\410\417.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        queue<pair<int, int>> q;
        auto bfs = [&](vector<vector<bool>>& arr) {
            static const vector<pair<int, int>> dirs = {
                { 1, 0 },
                { -1, 0 },
                { 0, -1 },
                { 0, 1 },
            };
            while (!q.empty()) {
                auto [i, j] = q.front();
                q.pop();
                for (auto [dx, dy] : dirs) {
                    int x = i + dx;
                    int y = j + dy;
                    if (x < 0 || x >= m || y < 0 || y >= n || arr[x][y]) {
                        continue;
                    }

                    if (heights[x][y] >= heights[i][j]) {
                        arr[x][y] = true;
                        q.emplace(x, y);
                    }
                }
            }
        };

        vector<vector<bool>> p(m, vector<bool>(n));
        vector<vector<bool>> a(m, vector<bool>(n));

        for (int j = 0; j < n; ++j) {
            p[0][j] = true;
            q.emplace(0, j);
        }

        for (int i = 1; i < m; ++i) {
            p[i][0] = true;
            q.emplace(i, 0);
        }

        bfs(p);

        for (int j = 0; j < n; ++j) {
            a[m - 1][j] = true;
            q.emplace(m - 1, j);
        }

        for (int i = 0; i < m - 1; ++i) {
            a[i][n - 1] = true;
            q.emplace(i, n - 1);
        }

        bfs(a);
        
        vector<vector<int>> ans;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (p[i][j] && a[i][j]) {
                    ans.push_back({ { i, j } });
                }
            }
        }

        return ans;
    }
};

TEST_EQUIVALENT(&Solution::pacificAtlantic)