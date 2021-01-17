/*
 * @Author: sanjusss
 * @Date: 2021-01-17 10:42:53
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-01-17 13:01:21
 * @FilePath: \C\C200\C220\C224\3.hpp
 */
#pragma once
#include "leetcode.h"

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 1) {
                    matrix[i][j] += matrix[i - 1][j];
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            sort(matrix[i].begin(), matrix[i].end());
            for (int j = n - 1; j >= 0; --j) {
                ans = max(ans, matrix[i][j] * (n - j));
            }
        }

        return ans;
    }
};