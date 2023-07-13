/*
 * @Author: sanjusss
 * @Date: 2023-07-13 10:13:18
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-07-13 10:28:08
 * @FilePath: \0\900\930\931.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = m - 2; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                int next = matrix[i + 1][j];
                if (j > 0) {
                    next = min(next, matrix[i + 1][j - 1]);
                }

                if (j + 1 < n) {
                    next = min(next, matrix[i + 1][j + 1]);
                }

                matrix[i][j] += next;
            }
        }

        return *min_element(matrix[0].begin(), matrix[0].end());
    }
};