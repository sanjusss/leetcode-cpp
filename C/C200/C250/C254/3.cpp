/*
 * @Author: sanjusss
 * @Date: 2021-08-15 10:33:17
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-15 11:07:03
 * @FilePath: \C\C200\C250\C254\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minNonZeroProduct(int p) {
        static const int64_t mod = 1e9 + 7;
        int64_t n_1 = (((int64_t)1 << p) - 1) % mod;
        int64_t n_2 = ((int64_t)1 << p) - 2;
        return (pow(n_2, n_2 / 2) * n_1) % mod;
    }

private:
    int64_t pow(int64_t a, int64_t b) {
        static const int64_t mod = 1e9 + 7;
        a %= mod;
        int64_t ans = 1;
        while (b > 0) {
            if (b & 1) ans = ans * a % mod;
            a = a * a % mod;
            b >>= 1;
        }

        return ans;
    }
};