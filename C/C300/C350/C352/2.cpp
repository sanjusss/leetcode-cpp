/*
 * @Author: sanjusss
 * @Date: 2023-06-25 10:25:09
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-07-02 10:38:55
 * @FilePath: \C\C300\C350\C352\2.cpp
 */
#include "leetcode.h"

static vector<int> primes;
static constexpr int maxI = 1e6;
static vector<bool> isPrime(maxI + 1, true);

static int init = [] () {
    isPrime[0] = false;
    isPrime[1] = false;
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
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>> ans;
        for (int i = 2; i <= n / 2; ++i) {
            if (isPrime[i] && isPrime[n - i]) {
                ans.push_back({ { i, n - i } });
            }
        }

        return ans;
    }
};