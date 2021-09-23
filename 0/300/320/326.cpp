/*
 * @Author: sanjusss
 * @Date: 2021-09-23 08:28:04
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-23 08:33:04
 * @FilePath: \0\300\320\326.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     bool isPowerOfThree(int n) {
//         if (n <= 0) {
//             return false;
//         }
        
//         while (n > 1) {
//             if (n % 3 == 0) {
//                 n /= 3;
//             }
//             else {
//                 break;
//             }
//         }

//         return n == 1;
//     }
// };

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};