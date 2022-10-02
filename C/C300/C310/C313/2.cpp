/*
 * @Author: sanjusss
 * @Date: 2022-10-02 10:26:39
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-02 10:34:49
 * @FilePath: \C\C300\C310\C313\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 2; i < m; ++i) {
            for (int j = 2; j < n; ++j) {
                int sum = 0;
                sum += grid[i - 2][j - 2];
                sum += grid[i - 2][j - 1];
                sum += grid[i - 2][j];
                sum += grid[i - 1][j - 1];
                sum += grid[i][j - 2];
                sum += grid[i][j - 1];
                sum += grid[i][j];
                ans = max(ans, sum);
            }
        }

        return ans;
    }
};