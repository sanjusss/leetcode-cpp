/*
 * @Author: sanjusss
 * @Date: 2021-06-06 10:28:36
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-06 10:43:06
 * @FilePath: \C\C200\C240\C244\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        return r0(mat, target, n) || r90(mat, target, n) || r180(mat, target, n) || r270(mat, target, n);
    }

private:
    bool r0(vector<vector<int>>& mat, vector<vector<int>>& target, int n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] != target[i][j]) {
                    return false;
                }
            }
        }

        return true;
    }

    bool r90(vector<vector<int>>& mat, vector<vector<int>>& target, int n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[j][n - 1 - i] != target[i][j]) {
                    return false;
                }
            }
        }

        return true;
    }

    bool r180(vector<vector<int>>& mat, vector<vector<int>>& target, int n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[n - 1 - i][n - 1 - j] != target[i][j]) {
                    return false;
                }
            }
        }

        return true;
    }

    bool r270(vector<vector<int>>& mat, vector<vector<int>>& target, int n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[n - 1 - j][i] != target[i][j]) {
                    return false;
                }
            }
        }

        return true;
    }
};

TEST(&Solution::findRotation)