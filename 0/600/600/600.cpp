/*
 * @Author: sanjusss
 * @Date: 2021-09-11 10:26:48
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-11 11:44:57
 * @FilePath: \0\600\600\600.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int findIntegers(int n) {
        vector<int> dp(32);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i < 32; ++i) {
            dp[i] = dp[i - 2] + dp[i - 1];
        }

        int ans = 0;
        for (int i = 30; i >= 0; --i) {
            if ((1 << i) & n) {
                ans += dp[i + 1];
                if ((1 << (i + 1)) & n) {
                    break;
                }
            }

            if (i == 0) {
                ++ans;
            }
        }

        return ans;
    }
};

TEST(&Solution::findIntegers)