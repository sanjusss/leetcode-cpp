/*
 * @Author: sanjusss
 * @Date: 2022-06-30 08:22:14
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-30 08:26:55
 * @FilePath: \1000\1100\1170\1175.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int numPrimeArrangements(int n) {
        static constexpr int64_t mod = 1e9 + 7;
        vector<bool> prime(n + 1, true);
        int cnt = 0;
        for (int i = 2; i <= n; ++i) {
            if (prime[i] == false) {
                continue;
            }

            ++cnt;
            for (int j = i + i; j <= n; j += i) {
                prime[j] = false;
            }
        }

        int64_t ans = 1;
        for (int i = 1; i <= cnt; ++i) {
            ans *= i;
            ans %= mod;
        }

        for (int i = n - cnt; i >= 1; --i) {
            ans *= i;
            ans %= mod;
        }


        return ans;
    }
};