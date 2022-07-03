/*
 * @Author: sanjusss
 * @Date: 2022-07-03 11:23:57
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-03 11:32:43
 * @FilePath: \C\C300\C300\C300\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countPaths(vector<vector<int>> &grid) {
        auto cmp = [&grid](const pair<int, int> &a, const pair<int, int> &b) {
            return grid[a.first][a.second] < grid[b.first][b.second];
        };
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                q.emplace(i, j);
            }
        }

        vector<vector<int64_t>> dp(m, vector<int64_t>(n));
        static constexpr int64_t mod = 1e9 + 7;
        static const vector<pair<int, int>> dirs = {
            { -1, 0 },
            { 1, 0 },
            { 0, -1 },
            { 0, 1 },
        };
        while (!q.empty()) {
            auto [i, j] = q.top();
            q.pop();
            dp[i][j] = 1;
            for (auto [dx, dy] : dirs) {
                int x = i + dx;
                int y = j + dy;
                if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] <= grid[i][j]) {
                    continue;
                }

                dp[i][j] += dp[x][y];
            }

            dp[i][j] %= mod;
            ans += dp[i][j];
            ans %= mod;
        }

        return ans;
    }
};