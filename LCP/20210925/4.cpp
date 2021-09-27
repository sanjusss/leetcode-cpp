/*
 * @Author: sanjusss
 * @Date: 2021-09-25 15:33:40
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-25 16:30:55
 * @FilePath: \LCP\20210925\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int securityCheck(vector<int>& capacities, int k) {
        static constexpr int64_t mod = 1000000007;
        vector<int64_t> dp(k + 1);
        dp[0] = 1;
        for (int i : capacities) {
            --i;

            for (int j = k - i; j >= 0; --j) {
                dp[j + i] += dp[j];
                dp[j + i] %= mod;
            }
        }

        return dp[k];
    }
};

TEST(&Solution::securityCheck)