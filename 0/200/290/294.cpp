/*
 * @Author: sanjusss
 * @Date: 2022-07-01 09:01:48
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-01 09:20:15
 * @FilePath: \0\200\290\294.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool canWin(string currentState) {
        unordered_map<uint64_t, bool> dp;
        int n = currentState.size();
        function<bool (uint64_t)> dfs = [&] (uint64_t mask) -> bool {
            if (dp.count(mask)) {
                return dp[mask];
            }

            bool res = false;
            for (int i = 1; i < n; ++i) {
                if ((mask & (1ull << i)) && (mask & (1ull << (i - 1)))) {
                    if (!dfs(mask ^ (3ull << (i - 1)))) {
                        res = true;
                        break;
                    }
                }
            }

            dp[mask] = res;
            return res;
        };
        uint64_t cur = 0;
        for (char i : currentState) {
            cur <<= 1;
            if (i == '+') {
                cur |= 1;
            }
        }

        return dfs(cur);
    }
};

TEST(&Solution::canWin)