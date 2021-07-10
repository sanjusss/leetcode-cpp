/*
 * @Author: sanjusss
 * @Date: 2021-07-04 10:28:53
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-04 10:56:28
 * @FilePath: \C\C200\C240\C248\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countGoodNumbers(long long n) {
        static constexpr int64_t mod = 1e9 + 7;
        if (n == 0) {
            return 1;
        }
        else if (n == 1) {
            return 5;
        }

        if (n % 2 == 1) {
            return (5ll * countGoodNumbers(n - 1)) % mod;
        }

        n /= 2;
        int64_t ans = 1;
        int64_t v = 20;
        while (n > 0) {
            if (n & 1) {
                ans *= v;
                ans %= mod;
            }

            v *= v;
            v %= mod;
            n >>= 1;
        }

        return ans;
    }
};