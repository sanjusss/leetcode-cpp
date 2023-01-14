/*
 * @Author: sanjusss
 * @Date: 2023-01-14 09:50:51
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-14 10:00:48
 * @FilePath: \0\400\460\465.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> cnt;
        for (auto& t : transactions) {
            cnt[t[0]] += t[2];
            cnt[t[1]] -= t[2];
        }

        vector<int> nums;
        for (auto [_, c] : cnt) {
            if (c != 0) {
                nums.push_back(c);
            }
        }

        int n = nums.size();
        vector<int> dp(1 << n, INT_MAX);
        dp[0] = 0;
        for (int mask = 0; mask < (1 << n); ++mask) {
            int sum = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    sum += nums[i];
                }
            }

            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    continue;
                }

                dp[mask | (1 << i)] = min(dp[mask | (1 << i)], dp[mask] + (sum + nums[i] == 0 ? 0 : 1));
            }
        }

        return dp.back();
    }
};

TEST(&Solution::minTransfers)