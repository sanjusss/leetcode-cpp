/*
 * @Author: sanjusss
 * @Date: 2023-02-19 10:29:14
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-02-19 11:55:22
 * @FilePath: \C\C300\C330\C333\3.cpp
 */
#include "leetcode.h"

static vector<int> primes;

static int init = [] () {
    static constexpr int maxI = 30;
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
    inline int64_t pow(int64_t a, int64_t b) {
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
public:
    int squareFreeSubsets(vector<int>& nums) {
        static constexpr int64_t mod = 1e9 + 7;
        vector<int> cnt(31);
        for (int i : nums) {
            ++cnt[i];
        }

        unordered_map<int64_t, int64_t> dp;
        dp[1] = Solution::pow(2, cnt[1]);
        for (int64_t i = 2; i <= 30; ++i) {
            bool success = true;
            vector<int> ps;
            for (int j : primes) {
                if (j > i) {
                    break;
                }
                else if (i % (j * j) == 0) {
                    success = false;
                    break;
                }
                else if (i % j == 0) {
                    ps.push_back(j);
                }
            }

            if (!success) {
                continue;
            }

            unordered_map<int64_t, int64_t> toAdd;
            for (auto [j, c] : dp) {
                success = true;
                for (int p : ps) {
                    if (p > j) {
                        break;
                    }
                    else if (j % p == 0) {
                        success = false;
                        break;
                    }
                }

                if (!success) {
                    continue;
                }

                toAdd[i * j] = (c * cnt[i]) % mod;
            }

            for (auto [j, c] : toAdd) {
                dp[j] += c;
                dp[j] %= mod;
            }
        }

        int64_t ans = 0;
        for (auto [_, c] : dp) {
            ans += c;
            ans %= mod;
        }

        ans += mod - 1;
        ans %= mod;
        return ans;
    }
};