/*
 * @Author: sanjusss
 * @Date: 2023-06-16 08:50:04
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-06-16 09:15:26
 * @FilePath: \1000\1400\1490\1494.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        vector<int> prepare(n);
        for (auto& r : relations) {
            prepare[r[1] - 1] |= 1 << (r[0] - 1);
        }

        int endMask = 1 << n;
        vector<int> dp(endMask, n);
        dp[0] = 0;
        for (int mask = 0; mask < endMask; ++mask) {
            int next = 0;
            bool valid = true;
            for (int i = 0; i < n && valid; ++i) {
                bool canSet = (mask & prepare[i]) == prepare[i];
                if (mask & (1 << i)) {
                    valid = canSet;
                }
                else {
                    if (canSet) {
                        next |= 1 << i;
                    }
                }
            }

            if (!valid) {
                continue;
            }

            for (int sub = next; sub > 0; sub = next & (sub - 1)) {
                if (__builtin_popcount(sub) > k) {
                    continue;
                }

                dp[mask | sub] = min(dp[mask] + 1, dp[mask | sub]);
            }
        }

        return dp[endMask - 1];
    }
};

TEST(&Solution::minNumberOfSemesters)