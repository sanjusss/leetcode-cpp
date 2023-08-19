/*
 * @Author: sanjusss
 * @Date: 2023-08-19 17:07:21
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-08-19 17:45:01
 * @FilePath: \1000\1400\1440\1444.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        static constexpr int mod = 1e9 + 7;
        const int m = pizza.size();
        const int n = pizza[0].size();
        vector<vector<int>> apples(m, vector<int>(n));
        vector<vector<int>> cur(m, vector<int>(n));
        vector<vector<int>> pre(m, vector<int>(n));
        for (int i = m - 1; i >= 0; --i) {
            int row = 0;
            for (int j = n - 1; j >= 0; --j) {
                row += pizza[i][j] == 'A' ? 1 : 0;
                if (i == m - 1) {
                    apples[i][j] = row;
                }
                else {
                    apples[i][j] = apples[i + 1][j] + row;
                }

                if (apples[i][j] > 0) {
                    cur[i][j] = 1;
                }
            }
        }

        for (int t = 2; t <= k; ++t) {
            swap(pre, cur);

            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    cur[i][j] = 0;
                    for (int x = i + 1; x < m; ++x) {
                        if (apples[i][j] > apples[x][j]) {
                            cur[i][j] += pre[x][j];
                            cur[i][j] %= mod;
                        }
                    }

                    for (int y = j + 1; y < n; ++y) {
                        if (apples[i][j] > apples[i][y]) {
                            cur[i][j] += pre[i][y];
                            cur[i][j] %= mod;
                        }
                    }
                }
            }
        }

        return cur[0][0];
    }
};