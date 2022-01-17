/*
 * @Author: sanjusss
 * @Date: 2022-01-17 08:51:48
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-17 09:16:46
 * @FilePath: \1000\1200\1220\1220.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countVowelPermutation(int n) {
        static constexpr int64_t mod = 1e9 + 7;
        int64_t a = 1;
        int64_t e = 1;
        int64_t i = 1;
        int64_t o = 1;
        int64_t u = 1;
        for (int j = 2; j <= n; ++j) {
            tie(a, e, i, o, u) = make_tuple(
                (e) % mod,
                ((a + i)) % mod,
                ((a + e + o + u)) % mod,
                ((i + u)) % mod,
                (a) % mod
            );
        }

        return (a + e + o + i + u) % mod;
    }
};

TEST(&Solution::countVowelPermutation)