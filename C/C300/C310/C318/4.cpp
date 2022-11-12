/*
 * @Author: sanjusss
 * @Date: 2022-11-06 10:51:17
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-12 15:19:30
 * @FilePath: /C/C300/C310/C318/4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        int n = robot.size();
        int m = factory.size();
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, INT64_MAX / 10000));
        dp[0][0] = 0;
        for (int i = 0; i < m; ++i) {
            dp[i + 1][0] = 0;
            int pos = factory[i][0];
            int lim = factory[i][1];
            for (int j = 0; j < n; ++j) {
                dp[i + 1][j + 1] = dp[i][j + 1];
                long long sum = 0;
                for (int k = 0; k < lim && k <= j; ++k) {
                    sum += abs(pos - robot[j - k]);
                    dp[i + 1][j + 1] = min(dp[i + 1][j + 1], sum + dp[i][j - k]);
                }
            }
        }

        return dp[m][n];
    }
};

TEST(&Solution::minimumTotalDistance)