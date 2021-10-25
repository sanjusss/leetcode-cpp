/*
 * @Author: sanjusss
 * @Date: 2021-10-25 09:24:02
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-25 09:26:43
 * @FilePath: \0\200\240\240_20211025.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = m - 1;
        int j = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] == target) {
                return true;
            }
            else if (matrix[i][j] > target) {
                --i;
            }
            else {
                ++j;
            }
        }

        return false;
    }
};