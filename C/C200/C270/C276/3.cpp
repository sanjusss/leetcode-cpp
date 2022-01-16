/*
 * @Author: sanjusss
 * @Date: 2022-01-16 10:27:49
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-16 10:56:35
 * @FilePath: \C\C200\C270\C276\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        long long n = questions.size();
        vector<long long> dp(n + 1);
        for (long long i = n - 1; i >= 0; --i) {
            long long p = questions[i][0];
            long long b = questions[i][1];
            if (i + b < n) {
                dp[i] = max(dp[i + 1], p + dp[i + b + 1]);
            }
            else {
                dp[i] = max(dp[i + 1], p);
            }
        }

        return dp[0];
    }
};