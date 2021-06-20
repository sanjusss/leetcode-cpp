/*
 * @Author: sanjusss
 * @Date: 2021-06-20 10:44:59
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-20 10:59:25
 * @FilePath: \C\C200\C240\C247\3.cpp
 */
#include "leetcode.h"

class Solution {
    struct Calc {
        Calc(vector<vector<int>>& grid1, vector<vector<int>>& grid2)
            : grid1(grid1), grid2(grid2), m(grid1.size()), n(grid1[0].size()) {
        }

        int count() {
            color1();
            int ans = 0;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid2[i][j] == 1 && grid1[i][j] > 0 && dfs2(i, j, grid1[i][j])) {
                        ++ans;
                    }
                }
            }

            return ans;
        }

        void color1() {
            int c = 2;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid1[i][j] == 1) {
                        dfs1(i, j, c++);
                    }
                }
            }
        }

        void dfs1(int i, int j, int c) {
            grid1[i][j] = c;
            for (auto [di, dj] : dirs) {
                int x = i + di;
                int y = j + dj;
                if (x < 0 || x >= m || y < 0 || y >= n || grid1[x][y] != 1) {
                    continue;
                }

                dfs1(x, y, c);
            }
        }

        bool dfs2(int i, int j, int c) {
            bool res = grid1[i][j] == c;
            grid2[i][j] = 0;
            for (auto [di, dj] : dirs) {
                int x = i + di;
                int y = j + dj;
                if (x < 0 || x >= m || y < 0 || y >= n || grid2[x][y] != 1) {
                    continue;
                }

                res = dfs2(x, y, c) && res;
            }

            return res;
        }

        vector<vector<int>>& grid1;
        vector<vector<int>>& grid2;
        int m;
        int n;
        vector<pair<int, int>> dirs = {
            { 1, 0 },
            { -1, 0 },
            { 0, 1 },
            { 0, -1 },
        };
    };

public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        return Calc(grid1, grid2).count();
    }
};