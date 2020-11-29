/*
 * @Author: sanjusss
 * @Date: 2020-11-29 14:21:09
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-11-29 14:25:54
 * @FilePath: \0\900\970\976.hpp
 */
#pragma once
#include "leetcode.h"

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        for (int i = A.size() - 1; i >= 2; --i) {
            if (A[i] < A[i - 1] + A[i - 2]) {
                return A[i] + A[i - 1] + A[i - 2];
            }
        }

        return 0;
    }
};