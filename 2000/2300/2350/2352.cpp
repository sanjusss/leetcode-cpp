/*
 * @Author: sanjusss
 * @Date: 2023-06-06 16:44:24
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-06-06 16:48:37
 * @FilePath: \2000\2300\2350\2352.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> cnt;
        for (auto& row : grid) {
            ++cnt[row];
        }

        int ans = 0;
        int n = grid.size();
        vector<int> col(n);
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < n; ++i) {
                col[i] = grid[i][j];
            }

            auto p = cnt.find(col);
            if (p != cnt.end()) {
                ans += p->second;
            }
        }

        return ans;
    }
};