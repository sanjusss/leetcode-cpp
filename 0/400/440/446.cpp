/*
 * @Author: sanjusss
 * @Date: 2021-08-11 10:58:48
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-11 11:32:31
 * @FilePath: \0\400\440\446.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return 0;
        }

        vector<unordered_map<int64_t, int>> dp(n);
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int64_t diff = (int64_t)nums[i] - (int64_t)nums[j];
                auto p = dp[j].find(diff);
                if (p == dp[j].end()) {
                    ++dp[i][diff];
                }
                else {
                    dp[i][diff] += p->second + 1;
                    ans += p->second;
                }
            }
        }

        return ans;
    }
};

TEST(&Solution::numberOfArithmeticSlices)