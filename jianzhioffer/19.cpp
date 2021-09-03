/*
 * @Author: sanjusss
 * @Date: 2021-09-03 11:18:25
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-03 11:18:25
 * @FilePath: \jianzhioffer\19.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (j == 0) {
                    dp[i][j] = i == 0;
                }
                else if (p[j - 1] == '.') {
                    dp[i][j] = i > 0 && dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*') {
                    if (j - 1 == 0) {
                        dp[i][j] = false;
                    }
                    else {
                        dp[i][j] = (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && (dp[i - 1][j - 1] || dp[i - 1][j] )) || dp[i][j - 2];
                    }
                }
                else {
                    dp[i][j] = i > 0 && dp[i - 1][j - 1] && s[i - 1] == p[j - 1];
                }
            }
        }

        return dp[m][n];
    }
};