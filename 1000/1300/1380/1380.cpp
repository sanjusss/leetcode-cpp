/*
 * @Author: sanjusss
 * @Date: 2022-02-15 11:20:28
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-15 11:35:35
 * @FilePath: \1000\1300\1380\1380.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> minInRow(m, INT_MAX);
        vector<int> maxInCol(n, INT_MIN);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                minInRow[i] = min(minInRow[i], matrix[i][j]);
                maxInCol[j] = max(maxInCol[j], matrix[i][j]);
            }
        }

        vector<int> ans;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (minInRow[i] == maxInCol[j]) {
                    ans.push_back(minInRow[i]);
                }
            }
        }

        return ans;
    }
};