/*
 * @Author: sanjusss
 * @Date: 2022-01-09 10:25:44
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-09 10:34:02
 * @FilePath: \C\C200\C270\C275\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<bool> has(n);
        for (int i = 0; i < n; ++i) {
            fill(has.begin(), has.end(), false);
            for (int j = 0; j < n; ++j) {
                has[matrix[i][j] - 1] = true;
            }

            for (bool h : has) {
                if (!h) {
                    return false;
                }
            }

            fill(has.begin(), has.end(), false);
            for (int j = 0; j < n; ++j) {
                has[matrix[j][i] - 1] = true;
            }

            for (bool h : has) {
                if (!h) {
                    return false;
                }
            }
        }

        return true;
    }
};