/*
 * @Author: sanjusss
 * @Date: 2021-05-13 08:23:00
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-13 08:33:10
 * @FilePath: \1000\1200\1260\1269.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int numWays(int steps, int arrLen) {
        static const int mod = 1e9 + 7;
        int n = min(1 + steps / 2, arrLen);
        vector<int> prev(n);
        vector<int> cur(n);
        cur[0] = 1;
        for (int i = 0; i < steps; ++i) {
            swap(prev, cur);
            fill(cur.begin(), cur.end(), 0);
            for (int j = 0; j < n; ++j) {
                cur[j] = (cur[j] + prev[j]) % mod;
                if (j > 0) {
                    cur[j - 1] = (cur[j - 1] + prev[j]) % mod;
                }

                if (j < n - 1) {
                    cur[j + 1] = (cur[j + 1] + prev[j]) % mod;
                }
            }
        }

        return cur[0];
    }
};

TEST(&Solution::numWays)