/*
 * @Author: sanjusss
 * @Date: 2024-04-12 08:50:10
 * @LastEditors: sanjusss
 * @LastEditTime: 2024-04-12 08:52:39
 * @FilePath: \2000\2900\2920\2923.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        for (int i = 1; i < n; ++i) {
            if (grid[i][ans]) {
                ans = i;
            }
        }

        return ans;
    }
};