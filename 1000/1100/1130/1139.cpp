/*
 * @Author: sanjusss
 * @Date: 2023-02-17 10:53:08
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-02-17 11:25:19
 * @FilePath: \1000\1100\1130\1139.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> iSums(m + 1, vector<int>(n + 1));
        vector<vector<int>> jSums(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    continue;
                }

                iSums[i + 1][j + 1] = iSums[i + 1][j] + 1;
                jSums[i + 1][j + 1] = jSums[i][j + 1] + 1;
            }
        }

        int ans = 0;
        for (int i = 0; i < m - ans; ++i) {
            for (int j = 0; j < n - ans; ++j) {
                if (grid[i][j] == 0) {
                    continue;
                }

                for (int k = ans + 1; i + k <= m && j + k <= n; ++k) {
                    if (iSums[i + 1][j + k] - iSums[i + 1][j] != k ||
                        jSums[i + k][j + 1] - jSums[i][j + 1] != k ||
                        iSums[i + k][j + k] - iSums[i + k][j] != k ||
                        jSums[i + k][j + k] - jSums[i][j + k] != k) {
                        continue;
                    }

                    ans = k;
                }
            }
        }

        return ans * ans;
    }
};

TEST(&Solution::largest1BorderedSquare)