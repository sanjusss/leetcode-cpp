/*
 * @Author: sanjusss
 * @Date: 2022-12-04 10:17:17
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-04 10:24:56
 * @FilePath: \1000\1700\1770\1774.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        static constexpr int maxV = 2e4;
        vector<bool> dp(maxV + 1);
        for (int i : baseCosts) {
            dp[i] = true;
        }

        for (int i : toppingCosts) {
            for (int j = 0; j < 2; ++j) {
                for (int k = maxV; k > i; --k) {
                    dp[k] = dp[k] || dp[k - i];
                }
            }
        }

        for (int i = 0; ; ++i) {
            if (target - i > 0 && dp[target - i]) {
                return target - i;
            }

            if (target + i <= maxV && dp[target + i]) {
                return target + i;
            }
        }

        return 0;
    }
};