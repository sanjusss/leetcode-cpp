/*
 * @Author: sanjusss
 * @Date: 2023-12-14 21:30:31
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-12-14 21:56:18
 * @FilePath: \2000\2100\2130\2132.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> sums(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                sums[i + 1][j + 1] = sums[i][j + 1] + sums[i + 1][j] - sums[i][j] + grid[i][j];
            }
        }

        vector<vector<int>> diffs(m + 2, vector<int>(n + 2));
        for (int i = 1; i + stampHeight - 1 <= m; i++) {
            for (int j = 1; j + stampWidth - 1 <= n; j++) {
                int x = i + stampHeight - 1;
                int y = j + stampWidth - 1;
                if (sums[x][y] - sums[x][j - 1] - sums[i - 1][y] + sums[i - 1][j - 1] == 0) {
                    diffs[i][j]++;
                    diffs[i][y + 1]--;
                    diffs[x + 1][j]--;
                    diffs[x + 1][y + 1]++;
                }
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                diffs[i][j] += diffs[i - 1][j] + diffs[i][j - 1] - diffs[i - 1][j - 1];
                if (diffs[i][j] == 0 && grid[i - 1][j - 1] == 0) {
                    return false;
                }
            }
        }

        return true;
    }
};