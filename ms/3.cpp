/*
 * @Author: sanjusss
 * @Date: 2021-06-19 15:00:31
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-19 15:28:11
 * @FilePath: \ms\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int largestArea(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] >= '1' && grid[i][j] <= '5') {
                    ans = max(ans, dfs(grid, m, n, i, j, grid[i][j]));
                }
            }
        }

        return ans;
    }

private:
    int dfs(vector<string>& grid, int m, int n, int i, int j, char target) {
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return 0;
        }

        if (grid[i][j] != target) {
            if (grid[i][j] == '0') {
                return -1;
            }
            else {
                return 0;
            }
        }

        grid[i][j] = '.';
        int cnt = 1;
        if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
            cnt = -1;
        }

        static const vector<pair<int, int>> dirs = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
        for (auto& [di, dj] : dirs) {
            int next = dfs(grid, m, n, i + di, j + dj, target);
            if (next < 0 || cnt < 0) {
                cnt = -1;
            }
            else {
                cnt += next;
            }
        }

        return cnt;
    }
};