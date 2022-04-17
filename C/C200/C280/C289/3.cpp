/*
 * @Author: sanjusss
 * @Date: 2022-04-17 10:28:09
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-04-17 11:15:37
 * @FilePath: \C\C200\C280\C289\3.cpp
 */

#include "leetcode.h"

class Solution {
public:
    int maxTrailingZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // if (m <= 1 || n <= 1) {
        //     return 0;
        // }

        vector<vector<int>> row2(m + 1, vector<int>(n + 1));
        vector<vector<int>> row5(m + 1, vector<int>(n + 1));
        vector<vector<int>> col2(m + 1, vector<int>(n + 1));
        vector<vector<int>> col5(m + 1, vector<int>(n + 1));
        vector<vector<int>> cnts2(m + 1, vector<int>(n + 1));
        vector<vector<int>> cnts5(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int cnt2 = getCnt(grid[i][j], 2);
                int cnt5 = getCnt(grid[i][j], 5);
                cnts2[i + 1][j + 1] = cnt2;
                cnts5[i + 1][j + 1] = cnt5;
                row2[i + 1][j + 1] = row2[i + 1][j] + cnt2;
                row5[i + 1][j + 1] = row5[i + 1][j] + cnt5;
                col2[i + 1][j + 1] = col2[i][j + 1] + cnt2;
                col5[i + 1][j + 1] = col5[i][j + 1] + cnt5;
            }
        }

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int left2 = row2[i + 1][j];
                int left5 = row5[i + 1][j];
                int right2 = row2[i + 1][n] - row2[i + 1][j + 1];
                int right5 = row5[i + 1][n] - row5[i + 1][j + 1];
                int top2 = col2[i][j + 1];
                int top5 = col5[i][j + 1];
                int bottom2 = col2[m][j + 1] - col2[i + 1][j + 1];
                int bottom5 = col5[m][j + 1] - col5[i + 1][j + 1];
                int cnt2 = cnts2[i + 1][j + 1];
                int cnt5 = cnts5[i + 1][j + 1];
                int lt = min(left2 + top2 + cnt2, left5 + top5 + cnt5);
                int lb = min(left2 + bottom2 + cnt2, left5 + bottom5 + cnt5);
                int rt = min(right2 + top2 + cnt2, right5 + top5 + cnt5);
                int rb = min(right2 + bottom2 + cnt2, right5 + bottom5 + cnt5);
                ans = max({ ans, lt, lb, rt, rb });
            }
        }

        return ans;
    }

private:
    int getCnt(int n, int base) {
        int cnt = 0;
        if (n > 0) {
            while (n % base == 0) {
                ++cnt;
                n /= base;
            }
        }

        return cnt;
    }
};

TEST(&Solution::maxTrailingZeros)