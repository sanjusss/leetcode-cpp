/*
 * @Author: sanjusss
 * @Date: 2023-02-19 10:29:07
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-02-19 11:28:47
 * @FilePath: \C\C300\C330\C333\2.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int minOperations(int n) {
//         int endMask = 1 << 18;
//         int ans = INT_MAX;
//         for (int mask = 0; mask < endMask; ++mask) {
//             int diff = 0;
//             int c = 0;
//             for (int i = 0; i < 16; ++i) {
//                 if (mask & (1 << i)) {
//                     diff += 1 << i;
//                     ++c;
//                 }
//             }
            
//             ans = min(ans, c + __builtin_popcount(n + diff));
//         }


//         return ans;
//     }
// };

class Solution {
public:
    int minOperations(int n) {
        int endMask = 1 << 18;
        int ans = INT_MAX;
        for (int mask = 0; mask < endMask; ++mask) {
            ans = min(ans, __builtin_popcount(mask) + __builtin_popcount(n + mask));
        }


        return ans;
    }
};

TEST(&Solution::minOperations)