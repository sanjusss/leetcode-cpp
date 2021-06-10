/*
 * @Author: sanjusss
 * @Date: 2021-06-10 08:23:57
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-10 08:29:04
 * @FilePath: \0\500\510\518_20210610.cpp
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

TEST(&Solution::change)