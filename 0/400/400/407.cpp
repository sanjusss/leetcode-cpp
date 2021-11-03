/*
 * @Author: sanjusss
 * @Date: 2021-11-03 08:45:44
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-11-03 10:44:37
 * @FilePath: \0\400\400\407.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        static const vector<pair<int, int>> dirs = {
            { 1, 0 },
            { -1, 0 },
            { 0, -1 },
            { 0, 1 }
        };

        int m = heightMap.size();
        int n = heightMap[0].size();
        vector<vector<bool>> pass(m, vector<bool>(n));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> q;

        for (int i = 0; i < m; ++i) {
            q.emplace(heightMap[i][0], i, 0);
            pass[i][0] = true;
            q.emplace(heightMap[i][n - 1], i, n - 1);
            pass[i][n - 1] = true;
        }

        for (int j = 1; j < n - 1; ++j) {
            q.emplace(heightMap[0][j], 0, j);
            pass[0][j] = true;
            q.emplace(heightMap[m - 1][j], m - 1, j);
            pass[m - 1][j] = true;
        }

        int ans = 0;
        while (!q.empty()) {
            auto [h, i, j] = q.top();
            q.pop();
            for (auto [di, dj] : dirs) {
                int x = i + di;
                int y = j + dj;
                if (x < 0 || x >= m || y < 0 || y >= n || pass[x][y]) {
                    continue;
                }

                pass[x][y] = true;
                int next = max(h, heightMap[x][y]);
                ans += next - heightMap[x][y];
                q.emplace(next, x, y);
            }
        }
        
        return ans;
    }
};

TEST(&Solution::trapRainWater)