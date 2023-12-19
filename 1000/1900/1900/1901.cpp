/*
 * @Author: sanjusss
 * @Date: 2023-12-19 09:09:00
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-12-19 10:07:04
 * @FilePath: \1000\1900\1900\1901.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int left = 0;
        int right = m - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            int j = max_element(mat[mid].begin(), mat[mid].end()) - mat[mid].begin();
            if (mid == m - 1 || mat[mid][j] > mat[mid + 1][j]) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return {{ left,  int(max_element(mat[left].begin(), mat[left].end()) - mat[left].begin()) }};
    }
};