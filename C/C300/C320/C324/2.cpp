/*
 * @Author: sanjusss
 * @Date: 2022-12-18 10:24:01
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-18 10:42:43
 * @FilePath: \C\C300\C320\C324\2.cpp
 */
#include "leetcode.h"

static vector<bool> isPrime;
static vector<int> primes;
static int init = [] () {
    static constexpr int maxV = 1e5;
    isPrime.resize(maxV + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i <= maxV; ++i) {
        if (!isPrime[i]) {
            continue;
        }

        primes.push_back(i);
        for (int j = i + i; j <= maxV; j += i) {
            isPrime[j] = false;
        }
    }

    return 0;
} ();

class Solution {
public:
    int smallestValue(int n) {
        int lastN = 0;
        while (!isPrime[n] && lastN != n) {
            lastN = n;
            int sum = 0;
            for (int i : primes) {
                if (i > n) {
                    break;
                }

                while (n % i == 0) {
                    n /= i;
                    sum += i;
                }
            }

            n = sum;
        }

        return n;
    }
};