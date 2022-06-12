/*
 * @Author: sanjusss
 * @Date: 2022-06-12 10:27:28
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-12 11:09:24
 * @FilePath: \C\C200\C290\C297\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        int allMask = (1 << n) - 1;
        vector<vector<int>> dp(k + 1, vector<int>(allMask + 1, INT_MAX / 2));
        dp[0][0] = 0;
        for (int i = 0; i < k; ++i) {
            for (int cur = 0; cur <= allMask; ++cur) {
                for (int next = 0; next <= allMask; ++next) {
                    if (cur & next) {
                        continue;
                    }

                    int cost = 0;
                    for (int j = 0; j < n; ++j) {
                        if (next & (1 << j)) {
                            cost += cookies[j];
                        }
                    }

                    dp[i + 1][cur | next] = min(dp[i + 1][cur | next], max(dp[i][cur], cost));
                }
            }
        }

        return dp[k][allMask];
    }
};