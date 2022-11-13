/*
 * @Author: sanjusss
 * @Date: 2022-11-13 10:26:02
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-13 11:03:47
 * @FilePath: \C\C300\C310\C319\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<int> dp(n + 1);
        for (int i = k - 1; i < n; ++i) {
            dp[i + 1] = dp[i];
            bool success = true;
            for (int j = k / 2 - 1; j >= 0; --j) {
                if (s[i - j] != s[i - k + 1 + j]) {
                    success = false;
                    break;
                }
            }

            if (success) {
                dp[i + 1] = max(dp[i - k + 1] + 1, dp[i + 1]);
            }

            if (i < k) {
                continue;
            }

            success = true;
            for (int j = (k + 1) / 2 - 1; j >= 0; --j) {
                if (s[i - j] != s[i - k + j]) {
                    success = false;
                    break;
                }
            }

            if (success) {
                dp[i + 1] = max(dp[i - k] + 1, dp[i + 1]);
            }
        }

        return dp[n];
    }
};

TEST(&Solution::maxPalindromes)