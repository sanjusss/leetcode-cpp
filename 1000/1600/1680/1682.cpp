#include "leetcode.h"

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<pair<int, char>>> dp(n, vector<pair<int, char>>(n));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j] && dp[i + 1][j - 1].second != s[j]) {
                    dp[i][j].first = dp[i + 1][j - 1].first + 2;
                    dp[i][j].second = s[j];
                }
                else {
                    if (dp[i + 1][j].first > dp[i][j - 1].first) {
                        dp[i][j] = dp[i + 1][j];
                    }
                    else {
                        dp[i][j] = dp[i][j - 1];
                    }
                }
            }
        }

        return dp[0][n - 1].first;
    }
};

TEST(&Solution::longestPalindromeSubseq)