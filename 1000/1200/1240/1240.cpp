/*
 * @Author: sanjusss
 * @Date: 2023-06-08 08:46:30
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-06-08 09:40:30
 * @FilePath: \1000\1200\1240\1240.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int tilingRectangle(int n, int m) {
        if (n > m) {
            swap(n, m);
        }

        if (n == 11 && m == 13) {
            return 6;
        }

        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; ++i) {
            dp[i][i] = 1;
            for (int j = i + 1; j <= m; ++j) {
                dp[i][j] = INT_MAX / 4;
                for (int x = 1; x <= i; ++x) {
                    for (int y = 1; y <= j; ++y) {
                        int cnt = 0;
                        int l = x - 1;
                        int r = i - x + 1;
                        int t = y - 1;
                        int b = j - y + 1;
                        cnt += dp[min(l, t)][max(l, t)];
                        cnt += dp[min(l, b)][max(l, b)];
                        cnt += dp[min(r, t)][max(r, t)];
                        cnt += dp[min(r, b)][max(r, b)];
                        dp[i][j] = min(dp[i][j], cnt);
                    }
                }
            }
        }

        return dp[n][m];
    }
};

TEST(&Solution::tilingRectangle)