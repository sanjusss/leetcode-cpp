/*
 * @Author: sanjusss
 * @Date: 2021-08-08 08:58:30
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-08 09:02:36
 * @FilePath: \jianzhioffer\58.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     string reverseLeftWords(string s, int n) {
//         return s.substr(n) + s.substr(0, n);
//     }
// };

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};