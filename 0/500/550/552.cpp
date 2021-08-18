/*
 * @Author: sanjusss
 * @Date: 2021-08-18 08:31:20
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-18 08:58:38
 * @FilePath: \0\500\550\552.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int checkRecord(int n) {
        static constexpr int64_t mod = 1e9 + 7;
        auto add = [](int64_t & a, int64_t & b) constexpr {
            a += b;
            a %= mod;
        };
        vector<int64_t> prev(8);
        vector<int64_t> cur(8);
        cur[0] = 1;
        for (int i = 0; i < n; ++i) {
            swap(prev, cur);
            fill(cur.begin(), cur.end(), (int64_t)0);

            for (int j = 0; j < 3; ++j) {
                int base = (j & 1) << 1;
                add(cur[base], prev[j]);
                add(cur[base | 1], prev[j]);
                add(cur[base | 4], prev[j]);
            }

            add(cur[2], prev[3]);
            add(cur[6], prev[3]);

            for (int j = 4; j < 7; ++j) {
                int base = ((j & 1) << 1) | 4;
                add(cur[base], prev[j]);
                add(cur[base | 1], prev[j]);
            }

            add(cur[6], prev[7]);
        }

        return accumulate(cur.begin(), cur.end(), (int64_t)0) % mod;
    }
};

TEST(&Solution::checkRecord)