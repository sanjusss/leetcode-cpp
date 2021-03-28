/*
 * @Author: sanjusss
 * @Date: 2021-03-28 10:50:43
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-03-28 11:23:14
 * @FilePath: \C\C200\C230\C234\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxNiceDivisors(int primeFactors) {
        static const int64_t mod = 1e9 + 7;
        if (primeFactors <= 3) {
            return primeFactors;
        }

        int64_t quotient = primeFactors / 3;
        int64_t remainder = primeFactors % 3;
        if (remainder == 0) {
            return pow(3, quotient);
        }
        else if (remainder == 1) {
            return pow(3, quotient - 1) * 4 % mod;
        }
        else {
            return pow(3, quotient) * 2 % mod;
        }
    }

private:
    int64_t pow(int64_t a, int64_t b) {
        static const int64_t mod = 1e9 + 7;
        int64_t ans = 1;
        while (b > 0) {
            if (b & 1) ans = ans * a % mod;
            a = a * a % mod;
            b >>= 1;
        }

        return ans;
    }
};