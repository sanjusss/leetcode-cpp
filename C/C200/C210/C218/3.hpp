/*
 * @Author: sanjusss
 * @Date: 2020-12-06 10:49:54
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-12-06 12:02:32
 * @FilePath: \C\C200\C210\C218\3.hpp
 */
#pragma once
#include "leetcode.h"

// class Solution {
// public:
//     int concatenatedBinary(int n) {
//         static const int64_t mod = 1e9 + 7;
//         int64_t ans = 0;
//         int cur = 0;
//         int next = 1;
//         for (int i = 1; i <= n; ++i) {
//             if (i & (1ll << cur)) {
//                 cur = next;
//                 ++next;
//             }
            
//             ans = ((ans << cur) + i) % mod;
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int concatenatedBinary(int n) {
        static const int64_t mod = 1e9 + 7;
        int64_t ans = 0;
        int bits = 0;
        int cur = 1;
        for (int i = 1; i <= n; ++i) {
            if (i == cur) {
                cur <<= 1;
                ++bits;
            }
            
            ans = ((ans << bits) + i) % mod;
        }

        return ans;
    }
};