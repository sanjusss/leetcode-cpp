/*
 * @Author: sanjusss
 * @Date: 2024-01-04 09:11:51
 * @LastEditors: sanjusss
 * @LastEditTime: 2024-01-04 09:23:53
 * @FilePath: \2000\2300\2390\2397.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> rows(m);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rows[i] |= matrix[i][j] << j;
            }
        }

        int endMask = 1 << m;
        int ans = 0;
        for (int mask = 1; mask < endMask; ++mask) {
            int cur = 0;
            for (int i = 0; i < m; ++i) {
                if (mask & (1 << i)) {
                    cur |= rows[i];
                }
            }

            if (__builtin_popcount(cur) <= numSelect) {
                ans = max(ans, __builtin_popcount(mask));
            }
        }

        return ans;
    }
};