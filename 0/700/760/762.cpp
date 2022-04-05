/*
 * @Author: sanjusss
 * @Date: 2022-04-05 11:08:29
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-04-05 11:12:36
 * @FilePath: \0\700\760\762.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        vector<bool> primes(33);
        primes[2] = true;
        primes[3] = true;
        primes[5] = true;
        primes[7] = true;
        primes[11] = true;
        primes[13] = true;
        primes[17] = true;
        primes[19] = true;
        primes[23] = true;
        primes[29] = true;
        primes[31] = true;
        int ans = 0;
        for (int i = left; i <= right; ++i) {
            if (primes[__builtin_popcount(i)]) {
                ++ans;
            }
        }

        return ans;
    }
};