#pragma once
#include "leetcode.h"

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> left(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> top(m + 1, vector<int>(n + 1, 0));
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    continue;
                }

                left[i + 1][j + 1] = 1 + left[i][j + 1];
                top[i + 1][j + 1] = 1 + top[i + 1][j];
                if (left[i + 1][j + 1] == 1) {
                    ans += top[i + 1][j + 1];
                }
                else if (top[i + 1][j + 1] == 1) {
                    ans += left[i + 1][j + 1];
                }
                else {
                    int h = top[i + 1][j + 1];
                    ans += h;
                    int kStart = i;
                    int kEnd = i + 1 - left[i + 1][j + 1];
                    for (int k = kStart; k > kEnd; --k) {
                        h = min(h, top[k][j + 1]);
                        ans += h;
                    }
                }
            }
        }

        return ans;
    }
};