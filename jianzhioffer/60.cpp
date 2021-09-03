/*
 * @Author: sanjusss
 * @Date: 2021-09-03 10:35:06
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-03 11:19:09
 * @FilePath: \jianzhioffer\60.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<int> dp(n * 6 + 1);
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = n * 6; j >= 0; --j) {
                dp[j] = 0;
                for (int k = 1; k <= 6 && j - k >= 0; ++k) {
                    dp[j] += dp[j - k];
                }
            }
        }

        double sum = accumulate(dp.begin(), dp.end(), 0);
        vector<double> ans;
        for (int i : dp) {
            if (i > 0) {
                ans.push_back(i / sum);
            }
        }

        return ans;
    }
};