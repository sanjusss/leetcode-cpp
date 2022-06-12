/*
 * @Author: sanjusss
 * @Date: 2022-06-12 10:27:28
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-12 10:51:04
 * @FilePath: \C\C200\C290\C297\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> cur = grid[0];
        vector<int> prev(n);
        for (int i = 1; i < m; ++i) {
            swap(prev, cur);
            fill(cur.begin(), cur.end(), INT_MAX);
            for (int jp = 0; jp < n; ++jp) {
                for (int jc = 0; jc < n; ++jc) {
                    cur[jc] = min(cur[jc], prev[jp] + moveCost[grid[i - 1][jp]][jc] + grid[i][jc]);
                }
            }
        }

        return *min_element(cur.begin(), cur.end());
    }
};