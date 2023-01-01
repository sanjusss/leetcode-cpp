/*
 * @Author: sanjusss
 * @Date: 2023-01-01 10:21:25
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-01 10:55:20
 * @FilePath: \C\C300\C320\C326\4.cpp
 */
#include "leetcode.h"

static vector<int> primes;

static int init = []() {
    static constexpr int maxI = 1e6;
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
}();

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> ans{ { -1, -1 } };
        if (left == right) {
            return ans;
        }

        auto b = lower_bound(primes.begin(), primes.end(), left);
        auto e = upper_bound(b, primes.end(), right);
        if (b == e) {
            return ans;
        }

        for (auto i = next(b); i != e; ++i) {
            int f = *prev(i);
            int s = *i;
            if (ans[0] == -1 || s - f < ans[1] - ans[0]) {
                ans[0] = f;
                ans[1] = s;
            }
        }

        return ans;
    }
};