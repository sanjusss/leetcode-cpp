/*
 * @Author: sanjusss
 * @Date: 2022-06-01 08:21:23
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-01 09:12:03
 * @FilePath: \0\400\470\473.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     bool makesquare(vector<int>& matchsticks) {
//         int all = accumulate(matchsticks.begin(), matchsticks.end(), 0);
//         if (all % 4 != 0) {
//             return false;
//         }

//         int edge = all / 4;
//         int n = matchsticks.size();
//         int allMask = (1 << n) - 1;
//         vector<int> masks;
//         for (int m = allMask; m > 0; --m) {
//             int e = 0;
//             for (int i = 0; i < n; ++i) {
//                 if (m & (1 << i)) {
//                     e += matchsticks[i];
//                 }
//             }

//             if (e == edge) {
//                 masks.push_back(m);
//             }
//         }

//         int cnt = masks.size();
//         int cur = 0;
//         for (int i = 0; i < cnt; ++i) {
//             cur = masks[i];
//             for (int j = i + 1; j < cnt; ++j) {
//                 if (cur & masks[j]) {
//                     continue;
//                 }

//                 cur |= masks[j];
//                 for (int k = j + 1; k < cnt; ++k) {
//                     if (cur & masks[k]) {
//                         continue;
//                     }

//                     return true;
//                 }

//                 cur ^= masks[j];
//             }
//         }

//         return false;
//     }
// };

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int all = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (all % 4 != 0) {
            return false;
        }

        int edge = all / 4;
        int n = matchsticks.size();
        int allMask = (1 << n) - 1;
        vector<int> dp(allMask + 1, -1);
        dp[0] = 0;
        for (int m = 1; m <= allMask; ++m) {
            for (int i = 0; i < n; ++i) {
                if (!(m & (1 << i))) {
                    continue;
                }

                int prev = m ^ (1 << i);
                if (dp[prev] >= 0 && dp[prev] + matchsticks[i] <= edge) {
                    dp[m] = (dp[prev] + matchsticks[i]) % edge;
                    break;
                }
            }
        } 

        return dp[allMask] == 0;
    }
};