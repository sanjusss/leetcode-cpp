/*
 * @Author: sanjusss
 * @Date: 2021-08-10 18:02:54
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-10 18:06:37
 * @FilePath: \jianzhioffer\04.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n == 0) {
            return false;
        }

        int m = matrix[0].size();
        if (m == 0) {
            return false;
        }

        int i = n - 1;
        int j = 0;
        while (i >= 0 && j < m) {
            if (matrix[i][j] == target) {
                return true;
            }
            else if (matrix[i][j] < target) {
                ++j;
            }
            else {
                --i;
            }
        }

        return false;
    }
};