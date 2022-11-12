/*
 * @Author: sanjusss
 * @Date: 2022-11-12 15:41:06
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-12 16:38:03
 * @FilePath: /0/700/790/790.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int numTilings(int n) {
        static constexpr int mod = 1e9 + 7;
        vector<int> dp(2 * n + 1);
        vector<int> one(2 * n + 1);

        dp[0] = 1;
        for (int i = 1; i <= 2 * n; ++i) {
            // 2
            if (i % 2 == 1) {
                if (i >= 3) {
                    dp[i] += one[i - 1] % mod;
                    dp[i] %= mod;
                    one[i] += dp[i - 3];
                    one[i] %= mod;
                }
            }
            else {
                dp[i] += dp[i - 2];
                dp[i] %= mod;
                if (i >= 3) {
                    dp[i] += one[i - 1] % mod;
                    dp[i] %= mod;
                    one[i] += dp[i - 3];
                    one[i] %= mod;
                }
            }

            // 3
            if (i % 2 == 1) {
                if (i >= 3) {
                    dp[i] += dp[i - 3];
                    dp[i] %= mod;
                }
            }
            else {
                if (i >= 4) {
                    dp[i] += dp[i - 3];
                    dp[i] %= mod;
                    dp[i] += one[i - 2];
                    dp[i] %= mod;
                    one[i] += dp[i - 4];
                    one[i] %= mod;
                }
            }
        }

        return dp[2 * n];
    }
};