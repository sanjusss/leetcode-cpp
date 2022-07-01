/*
 * @Author: sanjusss
 * @Date: 2022-07-01 16:52:54
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-01 17:09:34
 * @FilePath: \0\300\310\311.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m = mat1.size();
        int k = mat2.size();
        int n = mat2[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        if (m <= n) {
            for (int i1 = 0; i1 < m; ++i1) {
                for (int j1 = 0; j1 < k; ++j1) {
                    if (mat1[i1][j1] == 0) {
                        continue;
                    }

                    for (int j2 = 0; j2 < n; ++j2) {
                        ans[i1][j2] += mat1[i1][j1] * mat2[j1][j2];
                    }
                }
            }
        }
        else {
            for (int i2 = 0; i2 < k; ++i2) {
                for (int j2 = 0; j2 < n; ++j2) {
                    if (mat2[i2][j2] == 0) {
                        continue;
                    }
                    
                    for (int i1 = 0; i1 < m; ++i1) {
                        ans[i1][j2] += mat1[i1][i2] * mat2[i2][j2];
                    }
                }
            }
        }

        return ans;
    }
};

TEST(&Solution::multiply)