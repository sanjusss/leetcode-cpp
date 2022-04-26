/*
 * @Author: sanjusss
 * @Date: 2022-04-26 08:37:47
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-04-26 08:44:46
 * @FilePath: \0\800\880\883.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int hr = 0;
            int hc = 0;
            for (int j = 0; j < n; ++j) {
                hr = max(hr, grid[i][j]);
                hc = max(hc, grid[j][i]);
                ans += grid[i][j] > 0 ? 1 : 0;
            }

            ans += hr + hc;
        }

        return ans;
    }
};

TEST(&Solution::projectionArea)