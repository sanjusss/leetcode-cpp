/*
 * @Author: sanjusss
 * @Date: 2023-01-14 10:57:55
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-03-05 11:19:04
 * @FilePath: \解题模板\质数.h
 */
#include "leetcode.h"

static vector<int> primes;
static constexpr int maxI = 1000;
static vector<bool> isPrime(maxI + 1, true);

static int init = [] () {
    for (int i = 2; i <= maxI; ++i) {
        if (!isPrime[i]) {
            continue;
        }

        primes.push_back(i);
        for (int j = i + i; j <= maxI; j += i) {
            isPrime[j] = false;
        }
    }
    return 0;
} ();