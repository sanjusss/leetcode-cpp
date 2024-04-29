/*
 * @Author: sanjusss
 * @Date: 2024-04-29 14:18:25
 * @LastEditors: sanjusss
 * @LastEditTime: 2024-04-29 14:30:26
 * @FilePath: \1000\1300\1320\1329.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        for (int sub = -n + 1; sub < 0; ++sub) {
            vector<int> arr;
            for (int i = 0; i < m && i - sub < n; ++i) {
                arr.push_back(mat[i][i - sub]);
            }

            sort(arr.begin(), arr.end());
            for (int i = 0; i < m && i - sub < n; ++i) {
                mat[i][i - sub] = arr[i];
            }
        }

        for (int sub = 0; sub < m; ++sub) {
            vector<int> arr;
            for (int j = 0; j < n && j + sub < m; ++j) {
                arr.push_back(mat[j + sub][j]);
            }

            sort(arr.begin(), arr.end());
            for (int j = 0; j < n && j + sub < m; ++j) {
                mat[j + sub][j] = arr[j];
            }
        } 

        return mat;
    }
};

TEST(&Solution::diagonalSort)