/*
 * @Author: sanjusss
 * @Date: 2022-03-28 08:31:06
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-03-28 08:42:20
 * @FilePath: \0\600\690\693.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     bool hasAlternatingBits(int n) {
//         int prev = n & 1;
//         n >>= 1;
//         while (n > 0) {
//             int cur = n & 1;
//             if (cur == prev) {
//                 return false;
//             }

//             prev = cur;
//             n >>= 1;
//         }

//         return true;
//     }
// };

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int64_t t = n ^ (n >> 1);
        return (t & (t + 1)) == 0;
    }
};