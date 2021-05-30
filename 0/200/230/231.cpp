/*
 * @Author: sanjusss
 * @Date: 2021-05-30 09:56:00
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-30 09:59:20
 * @FilePath: \0\200\230\231.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//         int count = 0;
//         while (n > 0) {
//             ++count;
//             n &= n - 1;
//         }

//         return count == 1;
//     }
// };

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && !(n & (n - 1));
    }
};