/*
 * @Author: sanjusss
 * @Date: 2023-06-18 10:28:57
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-06-18 10:49:02
 * @FilePath: \C\C300\C350\C350\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int specialPerm(vector<int>& nums) {
        static constexpr int mod = 1e9 + 7;
        int n = nums.size();
        int allMask = (1 << n) - 1;
        vector<vector<int>> dp(n, vector<int>(allMask + 1));
        for (int i = 0; i < n; ++i) {
            dp[i][0] = 1;
        }

        for (int mask = 0; mask < allMask; ++mask) {
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    continue;
                }

                for (int j = 0; j < n; ++j) {
                    if (!(mask & (1 << j))) {
                        continue;
                    }

                    if (nums[i] % nums[j] != 0 && nums[j] % nums[i] != 0) {
                        continue;
                    }

                    dp[i][mask] += dp[j][mask ^ (1 << j)];
                    dp[i][mask] %= mod;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += dp[i][allMask ^ (1 << i)];
            ans %= mod;
        }

        return ans;
    }
};