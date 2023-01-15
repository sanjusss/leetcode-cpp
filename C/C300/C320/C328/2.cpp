/*
 * @Author: sanjusss
 * @Date: 2023-01-15 10:23:12
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-15 10:37:02
 * @FilePath: \C\C300\C320\C328\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> changes(n, vector<int>(n + 1));
        for (auto& q : queries) {
            for (int r = q[0]; r <= q[2]; ++r) {
                ++changes[r][q[1]];
                --changes[r][q[3] + 1];
            }
        }

        vector<vector<int>> ans(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            int v = 0;
            for (int j = 0; j < n; ++j) {
                v += changes[i][j];
                ans[i][j] = v;
            }
        }

        return ans;
    }
};