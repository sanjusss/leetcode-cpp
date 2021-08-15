/*
 * @Author: sanjusss
 * @Date: 2021-08-15 15:31:36
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-15 15:58:33
 * @FilePath: \0\500\570\576.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if (maxMove == 0) {
            return 0;
        }

        static constexpr int mod = 1e9 + 7;
        static const vector<pair<int, int>> dirs = {
            { 1, 0 },
            { -1, 0 },
            { 0, 1 },
            { 0, -1 }
        };
        auto key = [n] (int i, int j) { return i * n + j; };

        vector<int> arrive(m * n);//到达某点的次数
        vector<int> prev(m * n);
        vector<int> cur(m * n);
        cur[key(startRow, startColumn)] = 1;
        arrive[key(startRow, startColumn)] = 1;
        for (int move = 1; move < maxMove; ++move) {
            swap(cur, prev);
            fill(cur.begin(), cur.end(), 0);
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    int k = key(i, j);
                    if (prev[k] == 0) {
                        continue;
                    }

                    for (auto [dx, dy] : dirs) {
                        int x = i + dx;
                        int y = j + dy;
                        if (x < 0 || x >= m || y < 0 || y >= n) {
                            continue;
                        }

                        int z = key(x, y);
                        cur[z] += prev[k];
                        cur[z] %= mod;
                        arrive[z] += prev[k];
                        arrive[z] %= mod;
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            ans += arrive[key(i, 0)];
            ans %= mod;
            ans += arrive[key(i, n - 1)];
            ans %= mod;
        }

        for (int j = 0; j < n; ++j) {
            ans += arrive[key(0, j)];
            ans %= mod;
            ans += arrive[key(m - 1, j)];
            ans %= mod;
        }

        return ans;
    }
};

TEST(&Solution::findPaths)