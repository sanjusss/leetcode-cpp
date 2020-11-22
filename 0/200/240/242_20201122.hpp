/*
 * @Author: sanjusss
 * @Date: 2020-11-22 11:37:42
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-11-22 11:46:57
 * @FilePath: \0\200\240\242_20201122.hpp
 */
#pragma once
#include "leetcode.h"

// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         int scnt[26] = { 0 };
//         int tcnt[26] = { 0 };
//         for (char i : s) {
//             ++scnt[i - 'a'];
//         }

//         for (char i : t) {
//             ++tcnt[i - 'a'];
//         }

//         for (int i = 0; i < 26; ++i) {
//             if (scnt[i] != tcnt[i]) {
//                 return false;
//             }
//         }

//         return true;
//     }
// };

class Solution {
public:
    bool isAnagram(string s, string t) {
        int cnt[26] = { 0 };
        for (char i : s) {
            ++cnt[i - 'a'];
        }

        for (char i : t) {
            --cnt[i - 'a'];
        }

        for (int i : cnt) {
            if (i != 0) {
                return false;
            }
        }

        return true;
    }
};