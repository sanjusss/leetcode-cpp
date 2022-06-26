/*
 * @Author: sanjusss
 * @Date: 2022-06-26 10:29:44
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-26 10:39:42
 * @FilePath: \C\C200\C290\C299\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countHousePlacements(int n) {
        static constexpr int64_t mod = 1e9 + 7;
        int64_t c0 = 1;
        int64_t c1 = 0;
        for (int i = 0; i < n; ++i) {
            int64_t n0 = (c0 + c1) % mod;
            int64_t n1 = c0;
            c0 = n0;
            c1 = n1;
        }

        int64_t ans = (c0 + c1) % mod;
        ans *= ans;
        ans %= mod;
        return ans;
    }
};