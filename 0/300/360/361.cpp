/*
 * @Author: sanjusss
 * @Date: 2022-07-16 11:06:07
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-16 11:30:00
 * @FilePath: \0\300\360\361.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> values(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            int lefts = 0;
            int rights = 0;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 'W') {
                    lefts = 0;
                }
                else if (grid[i][j] == 'E') {
                    ++lefts;
                }
                else {
                    values[i][j] += lefts;
                }

                if (grid[i][n - 1 - j] == 'W') {
                    rights = 0;
                }
                else if (grid[i][n - 1 - j] == 'E') {
                    ++rights;
                }
                else {
                    values[i][n - 1 - j] += rights;
                }
            }
        }

        for (int j = 0; j < n; ++j) {
            int tops = 0;
            int bottoms = 0;
            for (int i = 0; i < m; ++i) {
                if (grid[i][j] == 'W') {
                    tops = 0;
                }
                else if (grid[i][j] == 'E') {
                    ++tops;
                }
                else {
                    values[i][j] += tops;
                }

                if (grid[m - 1 - i][j] == 'W') {
                    bottoms = 0;
                }
                else if (grid[m - 1 - i][j] == 'E') {
                    ++bottoms;
                }
                else {
                    values[m - 1 - i][j] += bottoms;
                }
            }
        }

        int ans = 0;
        for (auto& row : values) {
            for (int i : row) {
                ans = max(ans, i);
            }
        }

        return ans;
    }
};

TEST(&Solution::maxKilledEnemies)