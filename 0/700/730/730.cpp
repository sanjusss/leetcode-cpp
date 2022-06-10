/*
 * @Author: sanjusss
 * @Date: 2022-06-10 08:44:31
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-10 10:25:33
 * @FilePath: \0\700\730\730.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countPalindromicSubsequences(string s) {
        int n = s.size();
        static constexpr int64_t mod = 1e9 + 7;
        vector<vector<vector<int64_t>>> dp(4, vector<vector<int64_t>>(n, vector<int64_t>(n)));
        for (int i = n - 1; i >= 0; --i) {
            for (int k = 0; k < 4; ++k) {
                if (k == s[i] - 'a') {
                    dp[k][i][i] = 1;
                }
            }

            for (int j = i + 1; j < n; ++j) {
                for (int k = 0; k < 4; ++k) {
                    char c = k + 'a';
                    if (c == s[i] && c == s[j]) {
                        dp[k][i][j] = (2 + dp[0][i + 1][j - 1] + dp[1][i + 1][j - 1] + dp[2][i + 1][j - 1] + dp[3][i + 1][j - 1]) % mod;
                    }
                    else if (c == s[i]) {
                        dp[k][i][j] = dp[k][i][j - 1];
                    }
                    else if (c == s[j]) {
                        dp[k][i][j] = dp[k][i + 1][j];
                    }
                    else {
                        dp[k][i][j] = dp[k][i + 1][j - 1];
                    }
                }
            }
        }

        return (dp[0][0][n - 1] + dp[1][0][n - 1] + dp[2][0][n - 1] + dp[3][0][n - 1]) % mod;
    }
};

TEST(&Solution::countPalindromicSubsequences)