/*
 * @Author: sanjusss
 * @Date: 2023-04-22 17:33:15
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-04-22 17:43:37
 * @FilePath: \1000\1000\1020\1027.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        vector<int> pos(501, -1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int prev = nums[i] - (nums[j] - nums[i]);
                if (prev >= 0 && prev <= 500 && pos[prev] >= 0) {
                    dp[i][j] = dp[pos[prev]][i] + 1;
                }
                else {
                    dp[i][j] = 2;
                }

                ans = max(ans, dp[i][j]);
            }

            pos[nums[i]] = i;
        }

        return ans;
    }
};

TEST(&Solution::longestArithSeqLength)