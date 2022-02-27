/*
 * @Author: sanjusss
 * @Date: 2022-02-27 10:47:42
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-27 11:34:56
 * @FilePath: \C\C200\C280\C281\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        int n = tires.size();
        vector<int64_t> curtime(n);
        vector<int64_t> factor(n);
        for (int i = 0; i < n; ++i) {
            curtime[i] = tires[i][0];
            factor[i] = tires[i][0];
        }

        vector<int64_t> dp(numLaps + 1, INT_MAX);
        dp[1] = *min_element(curtime.begin(), curtime.end());
        bool useCurtime = true;
        for (int i = 2; i <= numLaps; ++i) {
            if (useCurtime) {
                for (int j = 0; j < n; ++j) {
                    factor[j] = min((int64_t)INT32_MAX, factor[j] * tires[j][1]);
                    curtime[j] = min((int64_t)INT32_MAX, curtime[j] + factor[j]);
                }

                dp[i] = *min_element(curtime.begin(), curtime.end());
                if (dp[i] >= dp[1] + changeTime) {
                    useCurtime = false;
                }
            }
            
            for (int j = i / 2; j > 0; --j) {
                if (dp[i] > dp[j] + dp[i - j] + changeTime) {
                    dp[i] = min(dp[i], dp[j] + dp[i - j] + changeTime);
                }
            }
        }

        return dp[numLaps];
    }
};

TEST(&Solution::minimumFinishTime)