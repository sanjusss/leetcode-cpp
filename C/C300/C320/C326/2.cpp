/*
 * @Author: sanjusss
 * @Date: 2023-01-01 10:21:25
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-01 10:39:16
 * @FilePath: \C\C300\C320\C326\2.cpp
 */
#include "leetcode.h"

static vector<int> primes;

static int init = [] () {
    static constexpr int maxI = 1000;
    vector<bool> isPrime(maxI + 1, true);
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

class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> ans;
        for (int i : nums) {
            for (int j : primes) {
                if (i < j) {
                    break;
                }

                if (i % j == 0) {
                    ans.insert(j);
                    do {
                        i /= j;
                    } while (i % j == 0);
                } 
            }
        }

        return ans.size();
    }
};