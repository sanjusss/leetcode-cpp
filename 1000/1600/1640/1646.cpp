/*
 * @Author: sanjusss
 * @Date: 2021-08-23 08:27:40
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-23 08:31:34
 * @FilePath: \1000\1600\1640\1646.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n < 2) {
            return n;
        }

        vector<int> dp(n + 1);
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            if (i & 1) {
                dp[i] = dp[i / 2] + dp[i / 2 + 1];
            }
            else {
                dp[i] = dp[i / 2];
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};