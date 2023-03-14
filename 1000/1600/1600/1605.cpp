/*
 * @Author: sanjusss
 * @Date: 2023-03-14 08:31:43
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-03-14 08:34:48
 * @FilePath: \1000\1600\1600\1605.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size();
        int n = colSum.size();
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int v = min(rowSum[i], colSum[j]);
                rowSum[i] -= v;
                colSum[j] -= v;
                ans[i][j] = v;
            }
        }

        return ans;
    }
};