/*
 * @Author: sanjusss
 * @Date: 2021-05-21 08:28:05
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-21 09:01:46
 * @FilePath: \1000\1000\1030\1035.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                if (nums1[i] == nums2[j]) {
                    dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
                }
            }
        }

        return dp[m][n];
    }
};

TEST(&Solution::maxUncrossedLines)