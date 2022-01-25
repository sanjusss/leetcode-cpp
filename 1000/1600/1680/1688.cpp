/*
 * @Author: sanjusss
 * @Date: 2022-01-25 08:24:30
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-25 08:27:16
 * @FilePath: \1000\1600\1680\1688.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int numberOfMatches(int n) {
//         int ans = 0;
//         while (n > 1) {
//             ans += n / 2;
//             n = n / 2 + n % 2;
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int numberOfMatches(int n) {
        return n - 1;
    }
};