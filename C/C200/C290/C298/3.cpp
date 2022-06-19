/*
 * @Author: sanjusss
 * @Date: 2022-06-19 10:29:03
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-19 10:55:54
 * @FilePath: \C\C200\C290\C298\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        vector<int64_t> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            int val = s[i] - '0';
            for (int j = i + 1; j > 0; --j) {
                dp[j] = min(dp[j], (dp[j - 1] << 1) + val);
            }
        }

        for (int i = n; i > 0; --i) {
            if (dp[i] <= k) {
                return i;
            }
        }

        return 0;
    }
};