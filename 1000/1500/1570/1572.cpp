/*
 * @Author: sanjusss
 * @Date: 2023-08-11 08:39:38
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-08-11 08:45:07
 * @FilePath: \1000\1500\1570\1572.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += mat[i][i];
            if (i != n - 1 - i) {
                sum += mat[i][n - 1 - i];
            }
        }

        return sum;
    }
};