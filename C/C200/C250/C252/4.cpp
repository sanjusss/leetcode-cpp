/*
 * @Author: sanjusss
 * @Date: 2021-08-01 10:28:46
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-01 11:24:37
 * @FilePath: \C\C200\C250\C252\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        static constexpr int64_t mod = 1e9 + 7;
        array<int64_t, 3> dp = { 0 };
        int64_t pow2 = 1;
        for (int i : nums) {
            if (i == 0) {
                pow2 = (pow2 * 2) % mod;
                dp[0] = (pow2 - 1) % mod;
            }
            else {
                dp[i] += dp[i] + dp[i - 1];
                dp[i] %= mod;
            }
        }
        
        return dp[2];
    }
};