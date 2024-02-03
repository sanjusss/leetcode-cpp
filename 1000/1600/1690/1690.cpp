#include "leetcode.h"

class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<int> sums(n + 1);
        for (int i = 0; i < n; ++i) {
            sums[i + 1] = sums[i] + stones[i];
        }

        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                // sum[i + 1, j] - dp[i + 1][j]
                // sum[i, j - 1] - dp[i + 1][j]
                dp[i][j] = max(sums[j + 1] - sums[i + 1] - dp[i + 1][j], sums[j] - sums[i] - dp[i][j - 1]);
            }
        }

        return dp[0][n - 1];
    }
};