/*
 * @Author: sanjusss
 * @Date: 2022-12-27 09:02:24
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-27 09:08:07
 * @FilePath: \2000\2000\2020\2027.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int minimumMoves(string s) {
//         int prev1 = 0;
//         int prev2 = 0;
//         int prev3 = 0;
//         for (char i : s) {
//             if (i == 'O') {
//                 prev3 = prev2;
//                 prev2 = prev1;
//             }
//             else {
//                 int cur = min({ prev1, prev2, prev3 }) + 1;
//                 prev3 = prev2;
//                 prev2 = prev1;
//                 prev1 = cur;
//             }
//         }

//         return prev1;
//     }
// };

class Solution {
public:
    int minimumMoves(string s) {
        int n = s.size();
        int prev = -3;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'O' || prev + 3 > i) {
                continue;
            }

            ++ans;
            prev = i;
        }

        return ans;
    }
};