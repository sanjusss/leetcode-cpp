/*
 * @Author: sanjusss
 * @Date: 2021-02-21 10:18:50
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-02-21 11:05:43
 * @FilePath: \C\C200\C220\C229\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        vector<vector<int>> dp(m + 1, vector<int>(m + 1));//dp[i][j]表示左边取i个、右边取j个后，剩余可以取用的最大值。
        for (int i = m - 1; i >= 0; --i) {
            for (int j = m - 1 - i; j >= 0; --j) {
                dp[i][j] = max(dp[i + 1][j] + nums[i] * multipliers[i + j], dp[i][j + 1] + nums[n - 1 - j] * multipliers[i + j]);
            }
        }

        return dp[0][0];
    }
};

TEST(&Solution::maximumScore)