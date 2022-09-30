/*
 * @Author: sanjusss
 * @Date: 2022-09-30 19:07:54
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-09-30 19:10:35
 * @FilePath: \chengxuyuanmianshijindian\0108_20220930.cpp
 */
#include "leetcode.h"

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            return;
        }

        int n = matrix[0].size();
        vector<bool> rows(m);
        vector<bool> cols(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rows[i] || cols[j]) {
                     matrix[i][j] = 0;
                }
            }
        }
    }
};

TEST_N(&Solution::setZeroes, 1)