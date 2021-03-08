#include "leetcode.h"

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPartition(n, vector<bool>(n, true));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    isPartition[i][j] = isPartition[i + 1][j - 1];
                }
                else {
                    isPartition[i][j] = false;
                }
            }
        }

        vector<int> dp(n, INT_MAX);
        for (int i = 0; i < n; ++i) {
            if (isPartition[0][i]) {
                dp[i] = 0;
            }
            else {
                for (int j = 1; j <= i; ++j) {
                    if (isPartition[j][i]) {
                        dp[i] = min(dp[i], dp[j - 1] + 1);
                    }
                }
            }
        }

        return dp[n - 1];
    }
};

TEST(&Solution::minCut)