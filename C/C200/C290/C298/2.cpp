/*
 * @Author: sanjusss
 * @Date: 2022-06-19 10:29:03
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-19 10:47:35
 * @FilePath: \C\C200\C290\C298\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minimumNumbers(int num, int k) {
        vector<int> dp(num + 1, INT_MAX / 2);
        dp[0] = 0;
        for (int i = num / 10; i >= 0; --i) {
            int c = i * 10 + k;
            for (int j = c; j <= num; ++j) {
                dp[j] = min(dp[j], dp[j - c] + 1);
            }
        }

        return dp[num] > num ? -1 : dp[num];
    }
};