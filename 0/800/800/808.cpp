/*
 * @Author: sanjusss
 * @Date: 2022-11-21 10:38:54
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-21 11:15:28
 * @FilePath: \0\800\800\808.cpp
 */
#include "leetcode.h"

static vector<vector<double>> dp(200, vector<double>(200));
static int maxN = []() -> int {
    dp[0][0] = 0.5;
    fill(dp[0].begin() + 1, dp[0].end(), 1.0);
    for (int i = 1; i < 200; ++i) {
        for (int j = 1; j < 200; ++j) {
            dp[i][j] = 0;
            dp[i][j] += dp[max(i - 4, 0)][j] ;
            dp[i][j] += dp[max(i - 3, 0)][max(j - 1, 0)];
            dp[i][j] += dp[max(i - 2, 0)][max(j - 2, 0)];
            dp[i][j] += dp[max(i - 1, 0)][max(j - 3, 0)];
            dp[i][j] /= 4.0;
        }

        if (abs(1 - dp[i][i]) < 1e-5) {
            return i;
        }
    }

    return 0;
}();

class Solution {
public:
    double soupServings(int n) {
        n = (n + 25 - 1) / 25;
        if (n >= maxN) {
            return 1;
        }
        else {
            return dp[n][n];
        }
    }
};

TEST(&Solution::soupServings)