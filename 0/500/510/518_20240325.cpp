/*
 * @Author: sanjusss
 * @Date: 2024-03-25 09:11:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2024-03-25 09:17:41
 * @FilePath: \0\500\510\518_20240325.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (int i : coins) {
            for (int j = i; j <= amount; ++j) {
                dp[j] += dp[j - i];
            }
        }

        return dp[amount];
    }
};