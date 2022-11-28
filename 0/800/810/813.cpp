/*
 * @Author: sanjusss
 * @Date: 2022-11-28 09:02:55
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-28 09:43:59
 * @FilePath: \0\800\810\813.cpp
 */
#include "leetcode.h"

class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(n + 1);
        for (int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + nums[i];
        }

        vector<vector<double>> dp(n + 1, vector<double>(k + 1, INT_MIN));
        dp[0][0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                double avg = (double)(sum[i + 1] - sum[j]) / (double)(i - j + 1);
                for (int l = min(j + 1, k); l > 0; --l) {
                    dp[i + 1][l] = max(dp[i + 1][l], dp[j][l - 1] + avg);
                }
            }
        }

        return *max_element(dp[n].begin(), dp[n].end());
    }
};

TEST(&Solution::largestSumOfAverages)