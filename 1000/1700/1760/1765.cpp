/*
 * @Author: sanjusss
 * @Date: 2022-01-29 09:44:23
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-29 10:02:15
 * @FilePath: \1000\1700\1760\1765.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isWater[i][j] == 1) {
                    ans[i][j] = 0;
                    q.emplace(i, j);
                }
            }
        }

        static const vector<pair<int, int>> dirs = {
            { 1, 0 },
            { -1, 0 },
            { 0, -1 },
            { 0, 1 }
        };
        int height = 0;
        while (!q.empty()) {
            for (int qi = q.size(); qi > 0; --qi) {
                auto [i, j] = q.front();
                q.pop();
                ans[i][j] = height;
                for (auto [dx, dy] : dirs) {
                    int x = i + dx;
                    int y = j + dy;
                    if (x < 0 || x >= m || y < 0 || y >= n || ans[x][y] != INT_MAX) {
                        continue;
                    }

                    ans[x][y] = 0;
                    q.emplace(x, y);
                }
            }
            
            ++height;
        }

        return ans;
    }
};