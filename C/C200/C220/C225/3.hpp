/*
 * @Author: sanjusss
 * @Date: 2021-01-24 11:09:54
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-01-24 11:20:48
 * @FilePath: \C\C200\C220\C225\3.hpp
 */
#pragma once
#include "leetcode.h"

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, greater<>> q;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> dpM(n + 1);
        vector<int> dpR(n + 1);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dpR[j + 1] = dpR[j] ^ matrix[i][j];
                dpM[j + 1] = dpM[j + 1] ^ dpR[j + 1];
                if (q.size() < k) {
                    q.push(dpM[j + 1]);
                }
                else if (dpM[j + 1] > q.top()) {
                    q.pop();
                    q.push(dpM[j + 1]);
                }
            }
        }

        return q.top();
    }
};