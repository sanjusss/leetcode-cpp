/*
 * @Author: sanjusss
 * @Date: 2022-07-12 09:55:18
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-12 10:49:40
 * @FilePath: \0\300\350\351.cpp
 */
#include "leetcode.h"

static constexpr int endMask = 1 << 9;
static vector<vector<int>> dp;
static int init = []() {
    vector<vector<int>> conds(9, vector<int>(9, -1));
    conds[0][6] = 3;
    conds[0][2] = 1;
    conds[0][8] = 4;

    conds[2][6] = 4;
    conds[2][0] = 1;
    conds[2][8] = 5;

    conds[6][2] = 4;
    conds[6][0] = 3;
    conds[6][8] = 7;

    conds[8][2] = 5;
    conds[8][0] = 4;
    conds[8][6] = 7;

    conds[1][7] = 4;
    conds[7][1] = 4;
    conds[3][5] = 4;
    conds[5][3] = 4;

    dp = vector<vector<int>>(endMask, vector<int>(9));
    for (int i = 0; i < 9; ++i) {
        dp[1 << i][i] = 1;
    }
    for (int mask = 1; mask < endMask; ++mask) {
        for (int last = 0; last < 9; ++last) {
            if (!(mask & (1 << last))) {
                continue;
            }

            for (int next = 0; next < 9; ++next) {
                if (mask & (1 << next)) {
                    continue;
                }

                if (conds[last][next] >= 0 && !(mask & (1 << conds[last][next]))) {
                    continue;
                }

                dp[mask | (1 << next)][next] += dp[mask][last];
            }
        }
    }
    return 0;
}();

class Solution {
public:
    int numberOfPatterns(int m, int n) {
        int ans = 0;
        for (int mask = 1; mask < endMask; ++mask) {
            int cnt = __builtin_popcount(mask);
            if (cnt >= m && cnt <= n) {
                ans += accumulate(dp[mask].begin(), dp[mask].end(), 0);
            }
        }

        return ans;
    }
};

TEST(&Solution::numberOfPatterns)