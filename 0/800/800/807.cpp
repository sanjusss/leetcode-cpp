/*
 * @Author: sanjusss
 * @Date: 2021-12-13 17:28:00
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-12-13 17:32:26
 * @FilePath: \0\800\800\807.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> imax(n);
        vector<int> jmax(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                imax[i] = max(imax[i], grid[i][j]);
                jmax[j] = max(jmax[j], grid[i][j]);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ans += max(0, min(imax[i], jmax[j]) - grid[i][j]);
            }
        }

        return ans;
    }
};