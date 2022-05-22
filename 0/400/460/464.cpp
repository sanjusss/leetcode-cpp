/*
 * @Author: sanjusss
 * @Date: 2022-05-22 14:43:35
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-05-22 15:19:04
 * @FilePath: \0\400\460\464.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     bool canIWin(int maxChoosableInteger, int desiredTotal) {
//         if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal) {
//             return false;
//         }

//         static constexpr int beginBit = 9;
//         static constexpr int valueMask = (1 << beginBit) - 1;
//         unordered_map<int, bool> dp;
//         function<bool(int)> dfs = [&](int cur) -> bool {
//             if (dp.count(cur)) {
//                 return dp[cur];
//             }

//             bool& res = dp[cur];
//             int value = cur & valueMask;
//             int mask = cur >> beginBit;
//             for (int i = 0; i < maxChoosableInteger; ++i) {
//                 int bit = 1 << i;
//                 if (bit & mask) {
//                     continue;
//                 }

//                 if (i + 1 >= value) {
//                     res = true;
//                     break;
//                 }

//                 int next = (mask | bit) << beginBit;
//                 next += value - i - 1;
//                 if (!dfs(next)) {
//                     res = true;
//                     break;
//                 }
//             }

//             return res;
//         };
//         return dfs(desiredTotal);
//     }
// };

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal) {
            return false;
        }

        static constexpr int beginBit = 9;
        static constexpr int valueMask = (1 << beginBit) - 1;
        vector<int> dp(1 << maxChoosableInteger);
        function<bool(int, int)> dfs = [&](int mask, int cur) -> bool {
            if (dp[mask] != 0) {
                return dp[mask] == 1;
            }

            bool res = false;
            for (int i = maxChoosableInteger; i > 0; --i) {
                int bit = 1 << (i - 1);
                if (mask & bit) {
                    continue;
                }

                if (i >= cur || !dfs(mask | bit, cur - i)) {
                    res = true;
                    break;
                }
            }

            dp[mask] = res ? 1 : -1;
            return res;
        };
        return dfs(0, desiredTotal);
    }
};

TEST(&Solution::canIWin)