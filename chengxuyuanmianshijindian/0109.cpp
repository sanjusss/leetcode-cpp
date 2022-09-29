/*
 * @Author: sanjusss
 * @Date: 2022-09-29 08:20:00
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-09-29 08:25:29
 * @FilePath: \chengxuyuanmianshijindian\0109.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     bool isFlipedString(string s1, string s2) {
//         if (s1.size() != s2.size()) {
//             return false;
//         }

//         int n = s1.size();
//         if (n == 0) {
//             return true;
//         }
//         else if (n == 1) {
//             return s1 == s2;
//         }

//         unordered_map<char, unordered_map<char, int>> conns1;
//         ++conns1[s1[n - 1]][s1[0]];
//         for (int i = 1; i < n; ++i) {
//             ++conns1[s1[i - 1]][s1[i]];
//         }

//         unordered_map<char, unordered_map<char, int>> conns2;
//         ++conns2[s2[n - 1]][s2[0]];
//         for (int i = 1; i < n; ++i) {
//             ++conns2[s2[i - 1]][s2[i]];
//         }

//         return conns1 == conns2;
//     }
// };

class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        return s1.size() == s2.size() && (s1 + s1).find(s2) != string::npos;
    }
};