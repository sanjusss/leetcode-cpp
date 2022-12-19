/*
 * @Author: sanjusss
 * @Date: 2022-12-11 10:19:23
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-11 10:33:29
 * @FilePath: \C\C300\C320\C323\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for (auto& r : grid) {
            sort(r.begin(), r.end());
        }

        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            int cur = grid[0][j];
            for (int i = 1; i < m; ++i) {
                cur = max(cur, grid[i][j]);
            }

            ans += cur;
        }

        return ans;
    }
};