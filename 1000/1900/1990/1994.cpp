/*
 * @Author: sanjusss
 * @Date: 2022-02-22 15:09:58
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-23 15:31:23
 * @FilePath: \1000\1900\1990\1994.cpp
 */
#include "leetcode.h"

int64_t bigpow(int64_t a, int64_t b) {
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

class Solution {
public:
    int numberOfGoodSubsets(vector<int>& nums) {
        static const int64_t mod = 1e9 + 7;
        vector<int64_t> cnt(31);
        for (int i : nums) {
            ++cnt[i];
        }
        
        static const int64_t primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
        static const int64_t goods[] = { 2, 3, 5, 6, 7, 10, 11, 13, 14, 15, 17, 19, 21, 22, 23, 26, 29, 30 };
        static const size_t n = sizeof(primes) / sizeof(int64_t);
        static const int end = 1 << n;
        vector<int64_t> dp(end);
        dp[0] = 1;
        for (int64_t i : goods) {
            if (cnt[i] == 0) {
                continue;
            }

            int cur = 0;
            for (int j = 0; j < n; ++j) {
                if (i % primes[j] == 0) {
                    cur |= 1 << j;
                }
            }

            for (int mask = end - 1; mask > 0; --mask) {
                if ((mask & cur) == cur) {
                    dp[mask] += dp[mask ^ cur] * cnt[i];
                    dp[mask] %= mod;
                }
            }
        }

        int64_t ans = 0;
        for (int i = 1; i < end; ++i) {
            ans += dp[i];
            ans %= mod;
        }

        ans *= bigpow(2, cnt[1]);
        ans %= mod;
        return ans;
    }
};


TEST(&Solution::numberOfGoodSubsets)