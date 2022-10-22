/*
 * @Author: sanjusss
 * @Date: 2022-10-20 08:39:48
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-20 08:53:11
 * @FilePath: \0\700\770\779.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int kthGrammar(int n, int k) {
//         vector<int> bits(n);
//         --k;
//         for (int i = n - 1; i >= 0; --i) {
//             bits[i] = k % 2;
//             k /= 2;
//         }

//         int ans = 0;
//         for (int i : bits) {
//             if (ans == 0) {
//                 if (i == 0) {
//                     ans = 0;
//                 }
//                 else {
//                     ans = 1;
//                 }
//             }
//             else {
//                 if (i == 0) {
//                     ans = 1;
//                 }
//                 else {
//                     ans = 0;
//                 }
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int kthGrammar(int n, int k) {
        return __builtin_popcount(k - 1) & 1;
    }
};