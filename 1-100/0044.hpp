#pragma once
#include "leetcode.h"
namespace _44 {
    class Solution {
    public:
        bool isMatch(string s, string p) {
            int sl = s.size();
            int pl = p.size();
            vector<vector<bool>> dp(sl + 1, vector<bool>(pl + 1));
            dp[0][0] = true;
            for (int j = 0; j < pl; ++j) {
                dp[0][j + 1] = dp[0][j] && p[j] == '*';
            }

            for (int i = 0; i < sl; ++i) {
                for (int j = 0; j < pl; ++j) {
                    if (p[j] == '?') {
                        dp[i + 1][j + 1] = dp[i][j];
                    }
                    else if (p[j] == '*') {
                        dp[i + 1][j + 1] = dp[i][j + 1] || dp[i + 1][j] || dp[i][j];
                    }
                    else {
                        dp[i + 1][j + 1] = dp[i][j] && s[i] == p[j];
                    }
                }
            }

            return dp[sl][pl];
        }
    };
}