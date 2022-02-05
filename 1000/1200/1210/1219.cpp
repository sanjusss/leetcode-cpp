/*
 * @Author: sanjusss
 * @Date: 2022-02-05 09:30:50
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-05 09:43:49
 * @FilePath: \1000\1200\1210\1219.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        static const vector<pair<int, int>> dirs = { { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } };
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            int gold = grid[i][j];
            int other = 0;
            grid[i][j] = 0;
            for (auto [dx, dy] : dirs) {
                int x = i + dx;
                int y = j + dy;
                if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0) {
                    continue;
                }

                other = max(other, dfs(x, y));
            }

            grid[i][j] = gold;
            return other + gold;
        };

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    ans = max(ans, dfs(i, j));
                }
            }
        }

        return ans;
    }
};