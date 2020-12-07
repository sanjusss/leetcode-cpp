#pragma once
#include "leetcode.h"

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();

        for (int i = 0; i < m; ++i) {
            if (A[i][0] == 1) {
                continue;
            }

            for (int j = 0; j < n; ++j) {
                if (A[i][j] == 0) {
                    A[i][j] = 1;
                }
                else {
                    A[i][j] = 0;
                }
            }
        }

        int halfN = (m + 1) / 2;
        for (int j = 0; j < n; ++j) {
            int k = 0;
            for (int i = 0; i < m; ++i) {
                if (A[i][j] == 1) {
                    ++k;
                }
            }

            if (k >= halfN) {
                continue;
            }

            for (int i = 0; i < m; ++i) {
                if (A[i][j] == 0) {
                    A[i][j] = 1;
                }
                else {
                    A[i][j] = 0;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            int v = 0;
            for (int j = 0; j < n; ++j) {
                v = (v << 1) + A[i][j];
            }

            ans += v;
        }

        return ans;
    }
};