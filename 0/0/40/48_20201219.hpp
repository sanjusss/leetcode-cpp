/*
 * @Author: sanjusss
 * @Date: 2020-12-19 15:42:40
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-12-19 16:31:05
 * @FilePath: \0\0\40\48_20201219.hpp
 */
#pragma once
#include "leetcode.h"

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int temp;
        int top;
        int left;
        int right;
        int bottom;
        int index;
        for (int i = 0; i < n / 2; ++i) {
            top = i;
            left = i;
            right = n - i - 1;
            bottom = n - i - 1;
            for (int j = left; j < right; ++j) {
                index = j - left;
                temp = matrix[top][left + index];
                matrix[top][left + index] = matrix[bottom - index][left];
                matrix[bottom - index][left] = matrix[bottom][right - index];
                matrix[bottom][right - index] = matrix[top + index][right];
                matrix[top + index][right] = temp;
            }
        }
    }
};